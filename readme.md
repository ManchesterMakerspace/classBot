#Makerspace class robot

This is some example code for the robot that we used in a class for the space

The example uses a library that gets around using "delay" to time actions.
Delay will eventually get in the way of bot multitasking.
So lets just not ever use it

So we need to basically do two things to set up setup the sketch and libary 

To use ( copy and paste way )
* add in "sketchbook"
* give folder name "mmClassBot" (exact case)
* put in files from this repo
* download JS_timer library https://github.com/PaulBeaudet/JS_Timer
* Put JS_timer library in libraries folder in sketchbook
* make sure folder name in libraies is JS_Timer with the library inside
* make sure your robot pin out line up with constants in motors.ino
* connect usb to your bot select the right port and upload!
* the bot does nothing! 
* open the serial monitor and send it M8... THEN M5! or uncomment "forward()"
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
