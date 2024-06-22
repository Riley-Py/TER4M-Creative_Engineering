Today, I didn't do much with the ESP32.  However, I did do some things to help me to prepare for tomorrow:

1. I found a video for how to get the ESP32 hooked up to WiFi and from there, can run a basic HTML script (hmm...if I have time, this can get pretty neat really quick, as I can get a user to connect to the IP address, put in a request to get a game, and then send that to an API). Below is the video: ![](https://www.youtube.com/watch?v=UuxBfKA3U5M)
2. I also found a video on how to parse JSON from the ESP32, in order for it to have usable data that I can then display onto the TFT display.  Below is that video: ![](https://www.youtube.com/watch?v=cgoCmYLeaSI)
3. I have ordered a new display that is guaranteed to work with the ESP32, and has a driver built-in to it from the TFT_eSPI page.  This should come within this week, so that gives me a few days to play around with APIs and see how I want to organize the information that I get from the JSON.
4. I have curated two free video game information APIs: IGDB and Pricecharting.  That way, I can experiment with both of them and see how they work.

If I can get this all done within the week, then I am thinking of adding the following (time-permitted):

1. Allow the user to input data using the HTML page, and then from there, the ESP32 makes a request to the API for that data and then displays that through LVGL onto the display
2. Make it so that I can switch screens remotely as I don't have a touchscreen any more 
3. Make it more intuitive for the user to connect to the remote server and make their modifications from there

This project is going well, and there is room for expansion if need be.  As well, documenting like this has helped me stay on track with the project and knowing what I need to get done next is very useful for me.

#Creative_Eng