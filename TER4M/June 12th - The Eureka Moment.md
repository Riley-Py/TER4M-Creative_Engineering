I started on the touchscreen as always, looking at the examples and seeing what I was missing.  Well, do I have news for you (more like me).  I was browsing around and happened stance found this [blog](https://iotexpert.com/mcu-friend-3-5-tft-identification/) that described how this one person found out their touchscreen model.  I wondered "Hey, maybe I chose the wrong display driver".  I look through the MCU_Friend.cpp file and found this:

![[driver.png]]

Right in the library, where the driver, instead of the ILI9486, could be an RM68140.  I tried out the driver and it came out the same as the ILI9486.  "Great", I thought, "What else could I do"?  Well, I then thought to calibrate the touchscreen, so I brought out the UNO to calibrate (since the tool only supports Arduino UNO), got values with using a stylus, and mapped those values in Arduino (mapping the values that I got from the touchscreen to a range between 0 and 480 for the x-coordinate, and 0 and 320 for the y-coordinate).  I upload the code, expecting it not to work and having to finally call it quits...but, as the odds would have it, *IT WORKS!* After four days and nights of work on this, it has finally come to fruition.  The video is on the bottom of it working:  

![[eureka.mp4]]

And here is the calibration data for the touchscreen: 


![[calibration 1.jpg]]

By doing all of this, I learned a valuable lesson: *Always calibrate before using*.  Even when you are using libraries, they may not accept certain values (especially on a touchscreen).  I am going to take a guess and say that LVGL didn't like the values presented, so it couldn't figure out the touch.  Tomorrow, I will be playing around with display drivers to see if I can get the screen working better.  

#Creative_Eng

