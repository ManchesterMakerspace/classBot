// mmClassBot.ino ~ Copyright Fall 2016 Paul Beaudet ~ License MIT
// This is example code for a bot meant for class at Manchester Makerspace
// Compiled with Arduino IDE 1.6.11

// dependancies: Call libraries
#include <JS_Timer.h>        // https://github.com/PaulBeaudet/JS_Timer
JS_Timer timer = JS_Timer(); // delay can be used, but a timer is better for multi-tasking
// Set up constant numbers
#define LED            13    // for debuging durring run time (pin 13)
#define MONITOR        0     // param for a polymorphic fuction that has a monitor mode
#define TRIGGER        1     // truth parameter = true || highs
#define OFFSET         13    // hard coded offset of the motors set this proper to drive straight
#define TEST_DURRATION 500   // durration in milliseconds
#define MAX_POWER      255   // max drive speed

// ----- Main Arduino functions ---------

void setup() {          // put your setup code here, to run once:
  Serial.begin(115200); // trun up Serial to over 9600 bps!
  motorSetup();         // instantiate motors
  // forwardTest();       // test going forward for Test durration
}

void loop() {          // put your main code here, to run repeatedly:
  timer.todoChecker(); // Polls when timing actions need to happen
  onListen();          // listens on serial port for commands
}

// ---- Your own functions ---- 

