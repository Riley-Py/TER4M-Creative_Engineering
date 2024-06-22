After staying up until 2:00 A.M at night trying to get a touchscreen working, I tried all day doing multiple methods, such as:

- Looking at many, *MANY*, forums, from Arduino and LVGL and trying to see if people had the same issues and trying out their fixes with fruitless results
- Trying out a different touchscreen library called [LovyanGFX](https://github.com/lovyan03/LovyanGFX), only to find out that they only support SPI TFT screens
- Trying out different versions of LVGL (switching between V7 and V8) numerous times and doing different things
- Trying out miscellaneous fixes (i.e. trying the touchscreen with the Adafruit library on the ESP32, verifying that it works, etc.)

However, later on, I started to use the serial monitor to try and see if there was data that was being received on the touchscreen.  I was originally following [this forum](https://daumemo.com/how-to-use-lvgl-library-on-arduino-with-an-esp-32-and-spi-lcd/#touch-input) for the touchscreen data, and did everything correct.  However, nothing was getting shown.  I was on the edge of giving up, but then I checked the pinout and, *lord and behold*, the pinout was wrong!  I changed the pinout to what I recorded from the MCUFriend library, and made sure to check if the pins were connected :

WR - 4;

RD - 2;

RS - 15;

CS - 33;

RST - 32;

d0 - 12;

d1 - 13;

d2 - 26;

d3 - 25;

d4 - 19;

d5 - 5;

d6 - 27;

d7 - 14;

Where, in my program, you have XM, XP, YP, YM.  What are they?  Well, in a 4-analog touch capable LCD screen, how it works is that there are 2 X-axis sides with one layer of the touchscreen (since this is a resistive touchscreen), and 2 Y-axis sides on the second layer.  When the screen is pressed, the resistance is changed.  Therefore, depending on the application, you can vary the resistance to control how responsive is.  

On the Arduino, XP and YM are connected to digital pins.  Meanwhile, the XM and YP are connected to analog pins.  I had to make sure, while wiring the touchscreen, that I was connected the XP and YM to touch-sensitive, digital pins on the ESP32 and that the XM and YP are connected to analog, touch-sensitive pins.  To find out these pins, I used the MCUfriend to tell me that D6, RS/DC (some touchscreens call this different things), WR, and D7 are the touch-capable pins.  

However, I still wasn't able to figure out why buttons on the touchscreen weren't working.  I gave myself until Wednesday to figure it out, and if I didn't, then I have move on and work the networking portion.  Hopefully some success tomorrow (spolier, since I am writing this in the future: There was!)

#Creative_Eng 