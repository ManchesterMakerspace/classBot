#Makerspace class robot

This is some example code for the robot that we used in a class for the space

To use ( copy and paste way )
* add in "sketchbook"
* give folder name "mmClassBot" (exact case)
* put in files from this repo
* make sure your robot pin out line up with constants
* connect usb to your bot select the right port and upload!
* the bot does nothing! (open the serial monitor and send it M8... THEN M5!)
* expriement with your own code!

non copy paste (not exact at all)
* open terminal
* cd ~/to-your/arduino/sketchbook
* git clone the-repository-url
* do everything after the 3rd bullet in the last list
 

Note: mmClassBot.ino which is same as folder name is our "starting place".
Making other files like motors.ino just provide a way to organize code.
The IDE takes code that you put in ino files in the same folder and arrages it in front of the setup function before compiling

There are some extra bits that allow for send commands over serial. This is meant to work with the "telezumo" project that can also be found on github
