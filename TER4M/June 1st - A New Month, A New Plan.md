When I woke up, I immediately got to work on figuring out what the hell the touchscreen was.  I installed the necessary libraries, and I ran the graphics test just to make sure I didn't get a defective touchscreen.  That came out good, as seen below: 

![[screen_working.mp4]]
This was decent news, but it still didn't solve the problem of why the ESP32 wasn't picking it up or anything.  I did more and more research into this, until I found out that the MCUfriend library can also pick up id hexcodes.  I ran that and the result came out to be "0x7575".  I didn't know what to make of it, and so common sense told me to search it up.  I found out that this was somewhat of a generic hexcode, and that it could have led to many different models with this formula "HXXXXX", starting with an "H" and a mixture of digits and numbers.  After some more research, I came across this YouTube video that showed me exactly what I needed to do to find out the mysterious "0x7575" hex code: 

![](https://www.youtube.com/watch?v=Tj-DjKAp770)

Right in the video, it showed my hex code of "0x7575" as being part of the driver named "HX8347G".  Yes, I finally found what the hell my TFT LCD touchscreen was! However, the bad news was that it was *not* an ILI9431 board nor was it supported by TFT_eSPI, as shown in this screenshot: 

![[bad_news.png]]

Someone was asking about adding the driver, but then the creator of the library stated that he didn't have an LCD with that specific controller and as a result, didn't create one.  This means that the TFT_eSPI can't be used with the touchscreen with the ESP32, and therefore no LVGL with the ESP32 can be used.

Here is a photo from a test that I did on the touchscreen:
![[testing.jpg]]



__________________________________________________________

As a result of this,  here are my following next steps for the project:

a) Get a screen that works - I don't necessarily need a touchscreen, as I can merely make a list and carousel through the list after so many seconds passing.  I will have to look on Amazon and make sure that the screen that I get is supported with TFT_eSPI

b) In the meantime, I will be playing around with trying to fetch data from an API and parsing/storing the data in variables, which would allow me to display it to LVGL when the new display does arrive.

It's a setback, but I've learned quite a bit on what to look for when it comes to finding out new screens and the compatibility of said screens.  I also know how to test the screens now to make sure they are what they say they are.  

#Creative_Eng