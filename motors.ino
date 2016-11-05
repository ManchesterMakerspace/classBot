// motor.ino ~ Copyright 2016 Paul Beaudet ~ MIT license

void motorSetup(){  
  motorShield.begin(); // start motors w/ default frequency 1.6KHz
}

void stopMotors(){
  leftMotor->run(RELEASE);  //
  rightMotor->run(RELEASE); //
  leftMotor->setSpeed(0);   // stop right motor
  rightMotor->setSpeed(0);  // stop left motor
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

void speedsSet(int leftPwr, int rightPwr){
  byte rightDirection = BACKWARD;
  byte leftDirection = BACKWARD;
  // Serial.println(leftPwr);
  if (leftPwr < 0){         // backward case
    leftPwr = abs(leftPwr);
  } else if(leftPwr > 0){   // forward case
    leftDirection = FORWARD;
  } else {                  // release case (brake would also be possible)
    rightPwr = 0;
    leftDirection = RELEASE;
  }
  if(rightPwr < 0){ // keep in mind backwards is default
    rightPwr = abs(rightPwr);
  } else if (rightPwr > 0){
    rightDirection = FORWARD;
  } else {
    rightPwr = 0;
    rightDirection = RELEASE;
  }
  // Serial.println(leftDirection);
  setDirections(leftDirection, rightDirection);
  setPower(leftPwr, rightPwr);
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

