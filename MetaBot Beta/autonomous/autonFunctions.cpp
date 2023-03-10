#include "vex.h"

void stopMotors(){
  LFM.stop(brake);
  RFM.stop(brake);
  LBM.stop(brake);
  RBM.stop(brake);
}

/*//This function moves the bot to the specified coordinates. The bot will always start at 0, 0 on startup. 
//If it times out, it will move on to the next function even if it still hasn't finished. 
//Units are in inches and seconds respectivley.
void goTo(double targetX, double targetY, double timeout, coordType coordinates)
{
  if (coordinates == RELATIVE){
    targetX += odom.getX();
    targetY += odom.getY();
  }
  TimeoutClock timer;
  PIDClass Speed(30, 0 ,0);

  while(vectorLength(targetX, targetY) > 2)
  {
    //Update PID Controller
    Speed.updatePID(vectorLength(targetX, targetY), 200);
    //Update Motor Speeds
    omniController(vectorGAngle(targetX, targetY), Speed.getOutput());
    
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
}*/

//This function turns the bot to the specified angle. The bot will start at 90 Degrees on startup.
//It will always take the shortest route to the target angle.
//Units are in Degrees and Seconds.
void turnTo(double targetAngle, double timeout)
{
  TimeoutClock timer;
  PIDClass Speed(4, 0, 0);

  while(angleDiff(odom.getAngle(DEGREES), targetAngle, DEGREES) > 1)
  {
    //Update PID Controller
    Speed.updatePID(turnDistance(targetAngle), 200); 

    
    LFM.spin(reverse, Speed.getOutput(), rpm);
    LBM.spin(reverse, Speed.getOutput(), rpm);
    RFM.spin(fwd, Speed.getOutput(), rpm);
    RBM.spin(fwd, Speed.getOutput(), rpm);

    if (timer.getTime() > timeout)
      break;

    wait(10, msec);
  }
  stopMotors();
}

//Spins the flywheel up to desired RPM and then shoots 2 disks.
//Units are in RPM.
void flywheel(int pow){  
  TimeoutClock timer;
  TimeoutClock timeout;
  PIDClass FlywheelPID(0.03, 0, 0);
  
  Flywheel1.spin(fwd, 600, rpm);
  Flywheel2.spin(fwd, 600, rpm);
  waitUntil(pow - avgRPM() < 5);

  timer.resetTime();
  while(timer.getTime() > 0.2){
    FlywheelPID.updatePID(pow - avgRPM(), 11 - FlywheelPID.getOutput());
    Flywheel1.spin(fwd, FlywheelPID.getOutput() + RPMtoVolts(pow), volt);
    Flywheel2.spin(fwd, FlywheelPID.getOutput() + RPMtoVolts(pow), volt);
    wait(10, msec);
    
    if (std::abs(avgRPM() - pow) > 30) {
      timer.resetTime();
    }

    if (timeout.getTime() > 6.75){
      break;
    }
  }

  shootDisk();
  wait(0.75, sec);
  Flywheel1.spin(fwd, 600, rpm);
  Flywheel2.spin(fwd, 600, rpm);
  waitUntil(pow - avgRPM() < -10);
  timer.resetTime();

  while(timer.getTime() > 0.2){
    FlywheelPID.updatePID(pow - avgRPM(), 11 - FlywheelPID.getOutput());
    Flywheel1.spin(fwd, FlywheelPID.getOutput() + RPMtoVolts(pow), volt);
    Flywheel2.spin(fwd, FlywheelPID.getOutput() + RPMtoVolts(pow), volt);
    wait(5, msec);
    
    if (std::abs(avgRPM() - pow) > 30) {
      timer.resetTime();
    }

    if (timeout.getTime() > 6.75){
      break;
    }
  }

  shootDisk();
  timer.resetTime();

  while(timer.getTime() < 0.75){
    FlywheelPID.updatePID(pow - avgRPM(), 11 - FlywheelPID.getOutput());
    Flywheel1.spin(fwd, FlywheelPID.getOutput() + RPMtoVolts(pow), volt);
    Flywheel2.spin(fwd, FlywheelPID.getOutput() + RPMtoVolts(pow), volt);
    wait(10, msec);
  }
  
  Flywheel1.stop(coast);
  Flywheel2.stop(coast);
}
  
//Toggles flywheel on or off depending on turnOn value
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

//Moves forwards or backwards depending on dir value
//Dir can be: fwd, forward, reverse
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

      wait(10, msec);
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

      wait(10, msec);
    }
  }
    stopMotors();
}

//Moves left or right depending on dir value
//Dir can be: left, right
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

      wait(10, msec);
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

      wait(10, msec);
    }
  }

  stopMotors();
}

//Toggles intake based on turn on value
//Dir can be: fwd, forward, reverse
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

//Rolls roller to right color
void roller(){
  LFM.spin(fwd, 15, rpm);
  LBM.spin(fwd, 15, rpm);
  RFM.spin(fwd, 15, rpm);
  RBM.spin(fwd, 15, rpm);

  Intake1.resetPosition();
  while(std::abs(Intake1.position(degrees)) < 90){
    Intake1.spin(reverse, 40, pct);
    Intake2.spin(reverse, 40, pct);
    wait(10, msec);
  }
  Intake1.stop(coast);
  Intake2.stop(coast);
  stopMotors();
}
