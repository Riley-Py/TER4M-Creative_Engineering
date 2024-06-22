Today was mostly spent on trying out display drivers and seeing which one works best.  Now, you may be thinking, "Riley, you already figured it out.  It was an RM68140 or an ILI9486".  Well, you may be surprised to know, but they don't display well, as observed below:

![[ILI9486.jpg]]
This is using the ILI9486 driver.  There is checkerboarding vertically.  I've researched into this and no one has this issue, making me think that I may have a faulty display.  

![[ILI9488.jpg]]
This is using the ILI9488 driver.  It shouldn't work at all, but it does, and it works better than the ILI9486 for some odd reason.  

With the RM68140, all it creates is rainbow streaks.  Tomorrow, I will test it with the Arduino and see if it is truly the display (spolier: It was).

#Creative_Eng 


