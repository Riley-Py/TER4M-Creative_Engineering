After my calculus test, I found myself in a pretty good mood to be working on my project.  I followed the instructions on how to the use the library, courtesy of the YouTube video below: 

![](https://www.youtube.com/watch?v=wdC3DRhCdgM)
    Of course, the video would be disable to be played back by the owner of the video

I wired it all up, tried out the library that he had along with the example project, and...nothing.  Well, not nothing, per se; it was just that the white screen stayed around.  I checked wiring and made sure I was using the right libraries, and I sure was.  So, I went on some more forums and I found out that the ILI9341 has many different models of touchscreens.  The controller is used on some SPI touchscreens and parallel touchscreens.  Now, I researched into what the difference was between SPI and parallel, and here is what I came up with:

- SPI stands for "Serial Peripheral Interface" and it's a pretty old standard way of communicating between other devices, like touchscreens.  The standard is almost guaranteed to be compatible with any modern micro-controller, but the flaw is that it is very slow.  Here is a video demonstrating the speed between SPI and parallel: 
![](https://www.youtube.com/watch?v=ZtCMIAmLSh8)

- On the other hand, with parallel interfaces, you have better colors, better framerates, and overall a better experience, but the flaw is the fact that they take up so many pins and them working on all hardware is very, VERY, hit or miss.  

I tried everything: Trying different pinouts; trying different wires.  Heck, I made a quick sanity check to see if power was going out from the ESP32 and making sure it wasn't defective.  Below is my simple circuit to check that the pin was working: 
![[light.jpg]]
    Very late at night, might I add...

I ruled out the ESP32 as being the culprit, but I hadn't ruled out the touchscreen just yet.  Before I went to bed, I found this tool called [MCUfriend](https://github.com/prenticedavid/MCUFRIEND_kbv) that would help with identifying the touchscreen once and for all by using an Arduino UNO.  I went to bed and hoped that I would be able to get to the bottom of this by tomorrow...

By the way, here is my sketch of the pin-outs of the touchscreen:
![[sticky_note.jpg]]


#Creative_Eng 
