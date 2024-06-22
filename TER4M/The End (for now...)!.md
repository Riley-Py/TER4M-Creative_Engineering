Here is my showcase for my project, "The Videogame Dashboard": ![[showcase.mp4]]
Here's how it works, step-by-step:

1. When you first launch the program, you get an IP address from the ESP32 and you put that into your browser
2. There, it loads a basic HTML form, where you can input game choices
3. Once your game choice is submitted, it moves on to the API call, where I format the string inputted by the user, make an API call using the HTTP library, and filters out the values that I want from the JSON file that is received into another JSON file, where the information from that one is parsed and inputted to the final step...
4. ...The UI!  I used LVGL for this, as I've had experience using it for robotics team, and as such, that made it simple to use to put the data onto the display

Now, on to the questions and answers:

## What Did I Do?

I made a video game dashboard using ESP32, HTTP libraries, an ILI9486/88 screen, and LVGL.  The API used to get the data was called [RAWG](https://rawg.io/) 

## Why Did I Do It?

I've always been fascinated by APIs ever since using the weather API from ICS4U, and I wanted to take that concept a bit further with displaying data from the API onto something that someone can see.  As well, my main hobby is video games/video game collecting (though I do eventually play them), so making something like this would be fun for the summer!

## What Were Your Essential Requirements?

My essential requirements were the following:

1. Create a decent UI that you can navigate 
2. Using the ESP32 to fetch data from APIs
3. Allowing user input to dictate what to get from the API
4. Displaying this information via LVGL

## Which Ones Did You Meet or Fail to Meet?

I met 2, 3, and 4 with great success.  However, with 1, that is more complicated.  See, getting touch to work was a pain in the ass, and then when I finally got it to register, it was off by a bit.  Right before calibrating it better, the touchscreen broke by transit, with the digitizer in particular (what makes touch possible).  If I didn't so much time trying to make it work, then I probably would have had time to make a more robust UI.  However, I think the most important part was learning all of these new concepts.

## What Are You Proud Of?

I am proud of the following:

- Persevering through the challenges that come with no-name touchscreens (identifying what they are, getting drivers working reliably, that there are specific touch pins that are used for the ESP32 etc.)
- Learning how to parse JSON through the use of the ArduinoJson library and filter the results out so that I can save on memory
- Learning how the ESP32 works and the quirks that come with it (i.e. translating the pins from Arduino to ESP32, learning that there are certain pins that you shouldn't use)
- Learning how to network with the ESP32 (which is entirely the whole point of the ESP32: being a WiFi-enabled Arduino without all of the flying antennas)
- Learning how LVGL works on a microcontroller and not done for you like it was for VEX (i.e. creating a buffer, knowing how information was written to the screen)
- Learning about TFT_eSPI and how to configure it (there is a separate file that you need to configure for it, like drivers)
- Learning the difference between parallel touchscreens and SPI touchscreens (Tl;dr: SPI are so much better for ESP32 due to less pins used and are more widely supported)

## What Would You Do Differently?

What I would do differently is the following:

- Following the instructions more precisely, and actually reading on what I am doing (for example, my touchscreen problem could have been resolved if I read that it need to be calibrated, which would have saved a bunch of time)
- Using a different touchscreen like an SPI that would allow for greater versatility (however, the parallel allowed me to troubleshoot quite a bit more and learn much more about touchscreens in general for Arduino)
- Creating a more versatile UI and maybe upgrading the ESP32 to another one that has more memory to allow for the expansion of this project, and adding cold-storage to it (in the form of an SD card extension or something along the lines of that)
- Taking better care of the touchscreen while in transit (not merely putting it in my bag)

Otherwise, I am very proud of what I've done.  I've only had a few weeks to figure all of this out, and in that time frame, I've learned much more than before and improved with efficiency and process than ever before!

#Creative_Eng