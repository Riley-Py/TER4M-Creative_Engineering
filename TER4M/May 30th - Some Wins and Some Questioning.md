When I worked on the project today, I furthered my research into how to get this display to turn on.  The first struggle was the fact that there wasn't one "singular" model of touchscreen out there.  There were many different types of touchscreens, all with different controllers and minor variances between each other.  Another issue was the fact that when I searched up my touchscreen on Amazon, hoping for some documentation, all I came across was this:
![[description.png]]
Really helpful.  No driver library, no instructions, just a simple spec sheet.  I continued to look further and further, down through the Arduino forums and other forums less widely accessed, until I came across this video, along with the blog associated with the person who made the video:

![](https://www.youtube.com/watch?v=4kKDSx9umts)

[The blog](https://iamleon99.blogspot.com/2023/04/esp32-ili9341parallelguislice.html)

Yes!  I finally found someone that had the same LCD as me (Riley from the future: You thought that, but later on, you would discover that these LCDs may look the same, but have variances that dramatically change how they work, particularly with libraries).  I wired it up like him, down to the exact wire diagram that he provided on his blog, and below is the result:
![[circuit_old_touchscreen.jpg]]


I got a white screen!  Oh, I got a white screen.  On the blog, I found a neat library called [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI), which at the time I thought would support my touchscreen.  The library is used to power various touchscreens, including the ILI9341 touchscreen that I have (or so I thought).  This was all the time I had for today, since I had to go and study for a calculus test, but I thought that I made some pretty good progress and would be on to testing LVGL on the touchscreen in no time.  Oh, how naive I was.


#Creative_Eng