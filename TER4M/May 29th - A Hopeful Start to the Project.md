
Today was the day that I started to work on my project for the next two weeks!  Here is my idea for the project:

- I had an ESP32 and a touchscreen laying around that was going to be used last semester, but due to working on robotics and the team (being a leader is time-consuming), I wasn't able to use them.  Now, however, I would be able to do this project since I have time to do this.
- With the ESP32, I would use it to fetch data from an API (requiring the use of JSON, and networking) that would be about gaming prices (I'm an avid game collector, so seeing this would be convenient for me to keep track of games that I currently have).   The ESP32 has a unique pin layout compared to Arduino, as pictured below: ![[esp32.png]]
    ESP32 Pin-out board

![[arduino.png]]
    Arduino Pin-out

This comes into play as there may have to be some translation of the pins from the Arduino to the ESP32 and so forth.  

- From there, the information would be displayed using a screen of some sort (touchscreen or otherwise) using the graphics library [LVGL](https://lvgl.io/) and showing off the data that was fetched from the ESP32

This project would be teaching me many things that I didn't know before, like:

- Fetching data from an API
- Using an ESP32
- Using a proper LCD/TFT display 
- Learning how to connect to the internet with the ESP32
- Learning the different pin-outs of the ESP32 and what they do
- Learning how to parse the information from JSON
- Learning more about LVGL and using it outside of what I have already used it for - robotics

Today, I started putting together the TFT screen and doing research on the libraries that I would need to get started. The TFT screen in particular was a ILI9341 controller touchscreen that was able to do parallel 8-bit colour (Riley from the future: this will come to bite you in the ass later on...) Here is a photo of that setup:
![[setup.jpg]]
When I tried turning it on, there was no display output.  I troubleshooted quite a bit today, but I had other things I had to do (tests, other projects, family commitments, etc).  As such, I left the project as was the photo until the next day.

#Creative_Eng