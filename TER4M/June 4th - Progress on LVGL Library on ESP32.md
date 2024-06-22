Today, I didn't get as much done as I'd had hoped due to the fact that LVGL, when not configured right out of the box (like how the LVGL library for PROS/VEX was) is a pain in the butt to set up yourself.  First, you have to set up a config file called "lv_conf.h".  It wasn't too hard; uncommenting some lines to allow TFT_eSPI to work.  I then went into the example file in the Arduino IDE, only to find that I have to configure the touchscreen, along with doing my own screen-buffering.  

I started with the touchscreen portion first.  I was looking at TFT_eSPI to see if they had that built-in...they do, but *not* for my specific touchscreen.  Instead, I have to resort to the one made by [Adafruit](https://github.com/adafruit/Adafruit_TouchScreen), courtesy of this [Arduino post](https://forum.arduino.cc/t/tft-espi-touch-demo-compile-error/873747/3).  I then ran the touchscreen test and came up with the pins that control touch on the LCD screen:

![[SchoolWork/TER4M/Images + Videos/calibration.jpg]]

From this screenshot, I know now which pins I need to use (and how to calibrate the LCD screen).  That's what I did today: put the code in for the touchscreen and verifying that it works.  Tomorrow is dealing with the display buffering and how to program that, and hopefully I can show a demo/example as the next image...

#Creative_Eng 