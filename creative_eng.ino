/*Author: Riley C.
  Course: TER4M
  Assignment: Creative Engineering ISU
  Description of program: Video game dashboard using an ILI9486 screen
  Libraries used: LVGL (Version 8.4), TFT_eSPI (Latest), HTTP (Latest), ArduinoJson (Latest), ESPAsyncWebServer (Latest), Adafruit touchscreen library (latest), when it worked :(
  Documentation: [INSERT GITHUB LINK, WITH OBSIDIAN JOURNAL AND THIS PROGRAM]
  */

/*Used LVGL for the UI; TFT_eSPI to support displaying, TouchScreen to get the touchscreen working (sadly touchscreen broke); 
and the rest of the libraries are used for getting data from an API though user input, using JSON as the file type, and getting data from the JSON*/
#include "lvgl.h"
//#include "TouchScreen.h"
#include "TFT_eSPI.h"
#include <WiFi.h>;
#include <HTTPClient.h>;
#include <ArduinoJson.h>;
#include <AsyncTCP.h>;
#include <ESPAsyncWebServer.h>;

// // touchscreen pins
// #define YP 4
// #define YM 14
// #define XP 27
// #define XM 15

//Website from IP address
AsyncWebServer server(80);

//Screen is 480x320
static const uint16_t screenWidth = 480;
static const uint16_t screenHeight = 320;

//Buffering for the contents of the touch screen
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 5];


//SSID and password for both home WiFi and school WiFi
const char* ssid_school = "amdsb-lab";
const char* password_school = "bsdmalab";

const char* ssid = "SmartRG-b81e";
const char* password = "10tobi30";


//HTML page that is rendered with the ESP32 as the server.  As well, "PROGMEM" means that this stuff is kept in dynamic (RAM) memory
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>Game List</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  </head><body>
  <form action="/get">
    Game Input: <input type="text" name="game">
    <input type="submit" value="Submit">
  </form><br>
</body></html>)rawliteral";



//Getting the point for the touchscreen
//TSPoint currPoint;

//Initializing the touchscreen for use
TFT_eSPI tft = TFT_eSPI(); 

//This would work with this screen if the digitzer worked.  See journal :(
//TouchScreen touchInput = TouchScreen(XP, YP, XM, YM, 300);

//Creating the web server that is used
void web_server() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  //Copy and paste IP address to get to the web page
  Serial.println(WiFi.localIP());
  
  //Creates the server, and allows devices to connect to it through the IP address
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });
  
  //On a button press, store the value that inputted into the text field, then send a request that acknowledges that it has been recieved. Finally, go to the next function
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    inputMessage = request->getParam("game")->value();

    request->send(200, "text/html", "Messaged recieved on ESP32: " + inputMessage +
                                     "<br><a href=\"/\">Return to Home Page</a>");

    data_fetching(inputMessage);

 });
 
 //Server runs on a separate core.  Hence why I can input things even though it has moved on to the next function
 server.begin();
}

//Getting the data from the API
void data_fetching(String input) {
  
  //Makes the input lower-case and replaces any space with a hyphen as the API uses hyphens instead of spaces
  input.toLowerCase();
  input.replace(" ", "-");
  
  //API that is used is rawg.io, which is a database full of videogames and has numerous information about video games
  const String URL = "https://api.rawg.io/api/games/" + input + "?key=fb03ada981894d8da025cc2fd06fa8e6";

  
  if (WiFi.status() == WL_CONNECTED) {
    
    //Starts the HTTP client and makes the GET request to the API
    HTTPClient client;
    client.begin(URL);
    
    //Gets the code from the GET request.  If it's 200, it's a success.  If it's 0, it's a failure
    int code = client.GET();

    if (code > 0) {

      //The load is the JSON file itself
      String load = client.getString();
      
      //With ArduinoJson, you can filter out prompts by storing it into a separate json, then getting rid of everything that isn't filtered
      StaticJsonDocument <200> filter;

      /*In this case, I wanted the following:
      - Name of video game
      - Metacritic score of game
      - When it was released
      - The amount of suggestions people made on the game
      - The ESRB rating for the game */
      filter["name"] = true;
      filter["metacritic"] = true;
      filter["released"] = true;
      filter["suggestions_count"] = true;
      filter["esrb_rating"] = true;
      
      //Makes the actual document, deserializes using the filter, then prints the output of the JSON to the serial monitor for debugging purposes
      StaticJsonDocument <400> doc;
      deserializeJson(doc, load, DeserializationOption::Filter(filter));
      serializeJsonPretty(doc, Serial);
      

      //Creates the parameters that I want to pass to the UI
      String name = doc["name"];
      int score = doc["metacritic"];
      String data = doc["released"];
      int suggestions = doc["suggestions_count"];
      String rating = doc["esrb_rating"]["name"];
      
    
      //Passes to the UI
      ui(name, score, data, suggestions, rating);

      
    }
    
  }
}

// Display flushing
static void flushDisplay(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    //Takes the width and height of the screen
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    
    //Sets the area that the TFT is going to be written to
    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    
    //Pushes the data until it's done, then ends it
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();
    

    //Tells LVGL that the flushing is ready
    lv_disp_flush_ready(disp);

}

//Deals with everything on the touchscreen
void ui(String name, int score, String released, int suggestions, String rating) {
    
  //Sets the rotation of the LCD (3 is landscape)
  tft.init();
  tft.setRotation(3);

  //For the touchscreen, as it needs to read analog inputs in, and ESP32 doesn't  read it in the bits that it needs to
  analogReadResolution(10);

  //Initializes LVGL and the buffer
  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * 5);

  //Initializes the display
  Serial.print("Initializing display... ");
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = tft.width();
  disp_drv.ver_res = tft.height();
  disp_drv.flush_cb = flushDisplay;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);
  Serial.println("Display Initialized!");
  
  //Cleans the screen so that when other requests are made from the webserver
  lv_obj_clean(lv_scr_act());
  
  
  //Style that is applied to each of the elements
  static lv_style_t text;
  lv_style_init(&text);
  lv_style_set_text_font(&text, &lv_font_montserrat_26);

  //Rest of the UI elements below
  Serial.print(name);
  lv_obj_t * label = lv_label_create(lv_scr_act());
  //lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
  lv_obj_set_width(label, 230);
  lv_label_set_text(label, name.c_str());
  lv_obj_add_style(label, &text, 0);
  lv_obj_align(label, LV_ALIGN_TOP_LEFT, 15, 60);

  lv_obj_t * label2 = lv_label_create(lv_scr_act());
  lv_obj_set_width(label2, 150);
  lv_label_set_text(label2, ("Metacritic score -  " + String(score)).c_str());
  lv_obj_add_style(label2, &text, 0);
  lv_obj_align(label2, LV_ALIGN_LEFT_MID, 15, -20);

  lv_obj_t * label3 = lv_label_create(lv_scr_act());
  lv_obj_set_width(label3, 145);
  lv_label_set_text(label3, ("Released " + released).c_str());
  lv_obj_add_style(label3, &text, 0);
  lv_obj_align(label3, LV_ALIGN_BOTTOM_LEFT, 15, -60);

  lv_obj_t * label4 = lv_label_create(lv_scr_act());
  lv_obj_set_width(label4, 165);
  lv_label_set_text(label4, ("Suggestions " + String(suggestions)).c_str());
  lv_obj_add_style(label4, &text, 0);
  lv_obj_align(label4, LV_ALIGN_TOP_RIGHT, -15, 50);

  lv_obj_t * label5 = lv_label_create(lv_scr_act());
  lv_obj_set_width(label5, 160);
  lv_label_set_text(label5, ("Rating " + rating).c_str());
  lv_obj_add_style(label5, &text, 0);
  lv_obj_align(label5, LV_ALIGN_RIGHT_MID, -15, 0);

  


}


// // read the touchpad
// void getTouchInput(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
// {
//     // a point object holds x y and z coordinates
//     uint16_t x, y;
//     currPoint = touchInput.getPoint();

//     pinMode(YP, OUTPUT); 
//     pinMode(XM, OUTPUT);
    
//     x = map(currPoint.y, 919, 337, 0, 320);
//     y = map(currPoint.x, 957, 205, 0, 480);
    

//     if (currPoint.z > touchInput.pressureThreshhold)
//     {
//         data->point.x = x;
//         data->point.y = y;
//         data->state = LV_INDEV_STATE_PR;
//         Serial.print("X = ");
//         Serial.print(currPoint.x);
//         Serial.print("\tY = ");
//         Serial.print(currPoint.y);
//         Serial.print("\tPressure = ");
//         Serial.println(currPoint.z);
//     }
//     else
//     {
//         data->state = LV_INDEV_STATE_REL;
//         //Serial.print("Released");
//     }
// }

//  void simple_button_event_handler(lv_event_t *e) {
//     lv_event_code_t code = lv_event_get_code(e);
//     if (code == LV_EVENT_CLICKED) {
//       Serial.println("Simple Button Pressed!");

//     }
    
    
// }


void setup()
{ 
    //Starts the serial monitor at 115200 baud rating (the rating that the ESP32 works best with)
    Serial.begin(115200);

    //Starts with the whole program
    web_server();
    
    
    
   
    

    // /*Initialize the touchpad*/
    // Serial.print("Initializing touchpad... ");
    // // lv_disp_drv_register(&disp_drv);
    // static lv_indev_drv_t indev_drv; // Descriptor of a touch driver
    // lv_indev_drv_init(&indev_drv);
    // indev_drv.type = LV_INDEV_TYPE_POINTER;
    // indev_drv.read_cb = getTouchInput;
    // lv_indev_t *my_indev = lv_indev_drv_register(&indev_drv);
    // if (my_indev == NULL)
    // {
    //     Serial.println("my_indev is NULL");
    // }
    // else
    // {
    //     Serial.println("my_indev is NOT NULL");
    // }
    //Serial.println("Touchpad Initialized!");

    
}



void loop()
{   
    //Timer for GUI and delay for it to work
    lv_task_handler(); 
    delay(1);
}
