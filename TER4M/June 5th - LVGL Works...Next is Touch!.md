Today was the day: I finally got LVGL working!  After looking at the LVGL forums, changing versions of libraries, and modifying code that I got from the internet, I ended up with the final result here: ![[lvgl_button.jpg]]
Now, this may be one button, but this is very, *very*, good.  This is one step closer towards easy UI development.  However, the LVGL version used is 8.4, while the latest is 9.1.  My plan is a simple one to rectify this issue:

1. Write all of the code in 8.4 and make sure it works (up to the touch stuff)
2. Convert the code to 9.1 so that it's cleaner and that I actually know what the hell is up with the programming

However, getting touch to work was something that I worked on today, but didn't get working.  I did find a link to a full-blown tutorial on how to use LVGL in conjunction with an LCD screen [here](https://daumemo.com/how-to-use-lvgl-library-on-arduino-with-an-esp-32-and-spi-lcd/#touch-input), so that can help me with getting touch done.  Tomorrow, I have Canada's Wonderland (assuming weather is a go), so I won't be able to work on this much tomorrow.  However, Friday is a P.D day, so I can catch up there and get touch functionality working.  After that, I am off to the races, where I can go back to trying to fetch data from a source and then displaying it onto the screen.

#Creative_Eng 