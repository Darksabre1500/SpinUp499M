#include "vex.h"

void stopMotors(){
  LFM.stop(brake);
  RFM.stop(brake);
  LBM.stop(brake);
  RBM.stop(brake);
}

//This function moves the bot to the specified coordinates. The bot will always start at 0, 0 on startup. 
//If it times out, it will move on to the next function even if it still hasn't finished. 
//Units are in inches and seconds respectivley.
void goTo(double targetX, double targetY, double timeout, coordType coordinates)
{
  if (coordinates == RELATIVE){
    targetX += odom.getX();
    targetY += odom.getY();
  }
  TimeoutClock timer;
  PIDClass Speed(30);

  while(vectorLength(targetX, targetY) > 2)
  {
    //Update PID Controller
    Speed.PID(vectorLength(targetX, targetY), 200);
    //Update Motor Speeds
    omniController(vectorGAngle(targetX, targetY), Speed.getPow());
    
    LFM.spin(fwd, Mfl, rpm);
    LBM.spin(fwd, Mbl, rpm);
    RFM.spin(fwd, Mfr, rpm);
    RBM.spin(fwd, Mbr, rpm);

    if (timer.getTime() > timeout){
      stopMotors();
      return;
    }

    wait(5, msec);
  }
  stopMotors();
}

//This function turns the bot to the specified angle. The bot will start at 90 Degrees on startup.
//It will always take the shortest route to the target angle.
//Units are in Degrees and Seconds.
void turnTo(double targetAngle, double timeout)
{
  TimeoutClock timer;
  PIDClass Speed(4);

  while(angleDiff(odom.getAngle(DEGREES), targetAngle, DEGREES) > 1)
  {
    //Update PID Controller
    Speed.PID(turnDistance(targetAngle), 200); 

    
    LFM.spin(reverse, Speed.getPow(), rpm);
    LBM.spin(reverse, Speed.getPow(), rpm);
    RFM.spin(fwd, Speed.getPow(), rpm);
    RBM.spin(fwd, Speed.getPow(), rpm);

    if (timer.getTime() > timeout)
      break;

    wait(5, msec);
  }
  stopMotors();
}

void flywheel(bool turOn, int pow){
  if (turOn){
    Flywheel1.spin(fwd, pow, rpm);
    Flywheel2.spin(fwd, pow, rpm);
  }
  else {
    Flywheel1.stop(coast);
    Flywheel2.stop(coast);
  }
}

void shootDisk(){
  Flicker.set(true);
  wait(0.125, sec);
  Flicker.set(false);
}

void move(double inches, directionType dir, double timeout){
  double init = degToIn(EncoderL.position(deg), 2.75);
  TimeoutClock timer;

  if(dir == fwd || dir == forward){
    while(degToIn(EncoderL.position(deg), 2.75) - init < inches)
    {    
      LFM.spin(fwd, 75, rpm);
      LBM.spin(fwd, 75, rpm);
      RFM.spin(fwd, 75, rpm);
      RBM.spin(fwd, 75, rpm);

      if (timer.getTime() > timeout){
        stopMotors();
        return;
      }

      wait(5, msec);
    }
  }

  else{
    while(degToIn(EncoderL.position(deg), 2.75) - init > -inches)
    {    
      LFM.spin(reverse, 75, rpm);
      LBM.spin(reverse, 75, rpm);
      RFM.spin(reverse, 75, rpm);
      RBM.spin(reverse, 75, rpm);

      if (timer.getTime() > timeout){
        stopMotors();
        return;
      }

      wait(5, msec);
    }
  }
    stopMotors();
}

void strafe(double inches, turnType dir, double timeout){
  double init = degToIn(EncoderS.position(deg), 2.75);
  TimeoutClock timer;
  
  if(dir == right){
    while(degToIn(EncoderS.position(deg), 2.75) - init < inches)
    {    
      LFM.spin(fwd, 200, rpm);
      LBM.spin(reverse, 200, rpm);
      RFM.spin(reverse, 200, rpm);
      RBM.spin(fwd, 200, rpm);

      if (timer.getTime() > timeout){
        stopMotors();
        return;
      }

      wait(5, msec);
    }
  }

  else{
    while(degToIn(EncoderS.position(deg), 2.75) - init > -inches)
    {    
      LFM.spin(reverse, 200, rpm);
      LBM.spin(fwd, 200, rpm);
      RFM.spin(fwd, 200, rpm);
      RBM.spin(reverse, 200, rpm);

      if (timer.getTime() > timeout){
        stopMotors();
        return;
      }

      wait(5, msec);
    }
  }

  stopMotors();
}

void intake(bool turnOn, directionType dir){
  if (turnOn){
    Intake1.spin(dir, 100, pct);
    Intake2.spin(dir, 100, pct);
  }
  else {
    Intake1.stop(coast);
    Intake2.stop(coast);
  }
}

void roller(colorType rollerColor){
  Intake1.spin(reverse, 25, pct);
  Intake2.spin(reverse, 25, pct);
  waitUntil(isRollerScored(rollerColor));
  Intake1.stop(coast);
  Intake2.stop(coast);
}