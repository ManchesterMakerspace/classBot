// remoteLogic.ino ~ Copyright 2016 Paul Beaudet ~ MIT License

#define MOVEMENT 'M' // signal char for direction change
#define SPEED    'S' // signal char for speed change
#define PROGRAM  'P' // signal char for programs
#define MUSIC    'C' // signal char for music
#define OFFSET   'O' // signal of how much to offest motors

char* gather(char incoming){  // returns if a command has been recieved
  static char packet[2] = { 0, 0 };  // store potential incoming command packet
                                     // reset if a full packet has been recieved
  if(packet[0] && packet[1]){packet[0] = 0; packet[1] = 0;}
  if(incoming){              // data available from Serial? 0xff signals no data
    if(packet[0]){          // do we already have the first char in packet?
      packet[1] = incoming; // then this this the second
      return packet;        // in this case a "packet" is 2 chars, we are done
    }                       // return pointer to first address of the packet
    else if(validCommand(incoming)){packet[0] = incoming;}
    // otherwise this is the first char in the packet, record it as such
  }
  return 0; // protocol does nothing until 
}

char validCommand(char cmd){
  if     (cmd == MOVEMENT){;}
  else if(cmd == SPEED){;}
  else if(cmd == PROGRAM){;}
  else if(cmd == MUSIC){;}
  else if(cmd == OFFSET){;}
  else{
    Serial.print(F("E:Invalid cmd ")); Serial.println(cmd);
    cmd = 0; // set command to zero if not a valid command
  }
  return cmd;
}

void onListen(){
  if(Serial.available()){                 // listen for serial events
    char* packet = gather(Serial.read()); // potential pointer to packet of incoming bytes
    if(packet){                           // if we have recieved a pointer to a packet
      if(packet[0] == MOVEMENT){          // if this is a movement packet
        steer(packet[1]);                 // do some driving in directions 
      } else if(packet[0] == SPEED){      // if this is a speed packet
        speedPower(packet[1]);            // change speed of zumo
      } else if(packet[0] == PROGRAM){    // if this is a program packet
        ;                                 // set a program mode
      } else if(packet[0] == MUSIC){      // music packet sent
        ;                                 // play a sound
      }
    }
  }
}

// steer constants
#define BACK_LEFT  '1'
#define BACK       '2'
#define BACK_RIGHT '3'
#define SPIN_LEFT  '4'
#define STOP       '5'
#define SPIN_RIGHT '6'
#define FWD_LEFT   '7'
#define FWD        '8'
#define FWD_RIGHT  '9'

void steer(char mode){
  if(mode){
    int pwr = speedPower(MONITOR); // figure current speed of bot
    
    if ( mode == STOP) {stopMotors();}
    else if( mode == BACK_LEFT) {
      setPower((pwr/2), pwr);
      setDirections(BACKWARD, BACKWARD);
    } else if( mode == BACK) {
      setPower(pwr, pwr);
      setDirections(BACKWARD, BACKWARD);
    } else if( mode == BACK_RIGHT){
      setPower(pwr, (pwr/2));
      setDirections(BACKWARD, BACKWARD);
    } else if( mode == SPIN_LEFT){
      setPower(pwr, pwr);
      setDirections(BACKWARD, FORWARD);
    } else if( mode == SPIN_RIGHT){
      setPower(pwr, pwr);
      setDirections(FORWARD, BACKWARD);
    } else if( mode == FWD_LEFT){
      setPower(pwr/2, pwr);
      setDirections(FORWARD, FORWARD);
    } else if( mode == FWD) {
      setPower(pwr, pwr);
      setDirections(FORWARD, FORWARD);
    } else if( mode == FWD_RIGHT){
      setPower(pwr, pwr/2);
      setDirections(FORWARD, FORWARD);
    } else {;} // put error case in this else
  }
}


void steer1(char mode){
  if(mode){
    int pwr = speedPower(MONITOR); // figure current speed of zumo
    if     ( mode == STOP)      {stopMotors();}
    else if( mode == BACK_LEFT) {speedsSet(-(pwr/2), -pwr);}
    else if( mode == BACK)      {speedsSet(-pwr, -pwr);}
    else if( mode == BACK_RIGHT){speedsSet(-pwr, -(pwr/2));}
    else if( mode == SPIN_LEFT) {speedsSet(-pwr, pwr);}
    else if( mode == SPIN_RIGHT){speedsSet(pwr, -pwr);}
    else if( mode == FWD_LEFT)  {speedsSet(pwr/2, pwr);}
    else if( mode == FWD)       {speedsSet(pwr, pwr);}
    else if( mode == FWD_RIGHT) {speedsSet(pwr, pwr/2);}
    else {;}
  }
}
