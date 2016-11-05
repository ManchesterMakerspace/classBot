// mmClassBot.ino ~ Copyright Fall 2016 Paul Beaudet ~ License MIT
// This is example code for a bot meant for class at Manchester Makerspace
// Compiled with Arduino IDE 1.6.11

// dependancies: Call libraries
#include <JS_Timer.h>             // https://github.com/PaulBeaudet/JS_Timer
#include <Adafruit_MotorShield.h> // https://github.com/adafruit/Adafruit_Motor_Shield_V2_Library

// Set up constant numbers
#define LED            13   // for debuging durring run time (pin 13)
#define MONITOR        0    // param for a polymorphic fuction that has a monitor mode
#define TRIGGER        1    // truth parameter = true || highs
#define OFFSET         13   // hard coded offset of the motors set this proper to drive straight
#define TEST_DURRATION 80   // durration in milliseconds
#define MAX_POWER      255  // max drive speed
#define LEFT_MOTOR_PORT 3   // motor number on Adafruit shield
#define RIGHT_MOTOR_PORT 4

// create library objects
JS_Timer timer = JS_Timer(); // delay can be used, but a timer is better for multi-tasking
Adafruit_MotorShield motorShield = Adafruit_MotorShield(); // Create motor shield object w/ default I2C address
Adafruit_DCMotor *leftMotor = motorShield.getMotor(LEFT_MOTOR_PORT);
Adafruit_DCMotor *rightMotor = motorShield.getMotor(RIGHT_MOTOR_PORT);

// ----- Main Arduino functions ---------

void setup() {          // put your setup code here, to run once:
  Serial.begin(115200); // turn up Serial to over 9600 bps!
  motorSetup();         // instantiate motors
  // forwardTest(400);// test going forward for Test durration
  // uhappyPlace();         // rock back and forth every x millis
  // backAndForth();
  otherHappyPlace();
}

void loop() {          // put your main code here, to run repeatedly:
  timer.todoChecker(); // Polls when timing actions need to happen
  onListen();          // listens on serial port for commands
}

// ---- Your own functions ---- 

void forwardTest(int durration){ // the folowing 4 instructions can be replaced w/ speedsSet()
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  leftMotor->setSpeed(MAX_POWER);          // fullspeed left
  rightMotor->setSpeed(MAX_POWER);         // fullspeed right
  timer.setTimeout(stopMotors, durration); // stop the motor in 5 seconds (5000 milliseconds)
}

void backAndForth(){
  setPower(MAX_POWER/2, MAX_POWER/2);
  setDirections(FORWARD, FORWARD);
  delay(100);
  setPower(MAX_POWER/2, MAX_POWER/2);
  setDirections(BACKWARD, BACKWARD);
  delay(100);
  stopMotors();
}

void happyPlace(){
  static bool toggle = true;

  setDirections(RELEASE, RELEASE);
  if(toggle){
    speedsSet(MAX_POWER/2, MAX_POWER/2);   // go forwards
  } else {
    speedsSet(-MAX_POWER/2, -MAX_POWER/2); // go backwards
  }
  toggle = !toggle;                    // flip toggle to opposite of toggle
  timer.setTimeout(happyPlace, TEST_DURRATION); // call yourself from within yourself (recursion)
}

void otherHappyPlace(){
  static bool toggle = true;

  if(toggle){
    setDirections(FORWARD, BACKWARD); // go forwards
  } else {
    setDirections(BACKWARD, FORWARD); // go backwards
  }
  toggle = !toggle;                    // flip toggle to opposite of toggle
  timer.setTimeout(otherHappyPlace, TEST_DURRATION); // call yourself from within yourself (recursion)
}
