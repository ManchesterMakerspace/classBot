// motor.ino ~ Copyright 2016 Paul Beaudet ~ MIT license
#include <Adafruit_MotorShield.h> // https://github.com/adafruit/Adafruit_Motor_Shield_V2_Library

#define LEFT_MOTOR_PORT 3  // motor number on Adafruit shield
#define RIGHT_MOTOR_PORT 4
Adafruit_MotorShield motorShield = Adafruit_MotorShield(); // Create motor shield object w/ default I2C address
Adafruit_DCMotor *leftMotor = motorShield.getMotor(LEFT_MOTOR_PORT);
Adafruit_DCMotor *rightMotor = motorShield.getMotor(RIGHT_MOTOR_PORT);

void motorSetup(){  
  motorShield.begin(); // start motors w/ default frequency 1.6KHz
}

void forwardTest(){
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  leftMotor->setSpeed(MAX_POWER);     // fullspeed left
  rightMotor->setSpeed(MAX_POWER);    // fullspeed right
  timer.setTimeout(stopMotors, 5000); // stop the motor in 5 seconds (5000 milliseconds)
}

void stopMotors(){
  leftMotor->run(RELEASE);  //
  rightMotor->run(RELEASE); //
  leftMotor->setSpeed(0);   // stop right motor
  rightMotor->setSpeed(0);  // stop left motor
}


void speedsSet(byte leftPwr, byte rightPwr){
  byte rightDir = BACKWARD;
  byte leftDir = BACKWARD;
  if(leftPwr){             // forward case
    leftDir = FORWARD;
  } else if (leftPwr < 0){ // backward case
    leftPwr = abs(leftPwr);
  } else {                 // release case (brake would also be possible)
    leftDir = RELEASE;
    // leftDir = BRAKE;
  }
  if(rightPwr){
    rightDir = FORWARD;
  } else if (rightPwr < 0){ // keep in mind backwards is default
    rightPwr = abs(rightPwr);
  } else {
    rightDir = RELEASE;
    // rightDir = BREAK;
  }

  leftMotor->setSpeed(leftPwr);
  leftMotor->run(leftDir);
  rightMotor->setSpeed(rightPwr);
  rightMotor->run(rightDir);
}

void setDirections(byte left, byte right){
  leftMotor->run(left);
  rightMotor->run(right);
}

void setPower(byte left, byte right){
  leftMotor->setSpeed(left);
  rightMotor->setSpeed(right);
}

void releaseMotors(){
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
}

int speedPower(char mode){
  static int botPower = MAX_POWER; // defualt to maximum power
  if(mode){
    if     (mode == '1'){botPower = MAX_POWER * 0.25;} // 25% spd
    else if(mode == '2'){botPower = MAX_POWER * 0.50;} // 50% spd
    else if(mode == '3'){botPower = MAX_POWER * 0.75;} // 75% spd
    else if(mode == '4'){botPower = MAX_POWER;}
    else{;} // put error case here
  }
  return botPower;
}

char offsetPower(char mode){
  static char botOffset = DEFAULT_OFFSET; // defualt to maximum power
  if (mode == OFFSET_MONITOR){ return botOffset;}
  botOffset = mode;
}

