#include "vex.h"

  void stopMotors(){
    LFM.stop(brake);
    RFM.stop(brake);
    LBM.stop(brake);
    RBM.stop(brake);
  }

  double botAngle(bool flipped){
    if (flipped == false)
      return angleWrap(odom.getAngle(DEGREES) + 180, DEGREES);
    else 
      return odom.getAngle(DEGREES);
  }

 //This function moves the bot to the specified coordinates. The bot will always start at 0, 0 on startup. 
//If it times out, it will move on to the next function even if it still hasn't finished. 
//Units are in inches and seconds respectivley.
void GoTo(double target_X, double target_Y, double PID, double timeout, coordType coordinates, bool facingFront)
{
  if (coordinates == RELATIVE){
    target_X += odom.getX();
    target_Y += odom.getY();
  }
  TimeoutClock timer;
  double initRRot = EncoderR.rotation(deg);
  double initLRot = EncoderL.rotation(deg);

  PIDClass RPID(1.15);
  RotationController Rot(radiansToDeg(vectorGAngle(target_X, target_Y)), RPID);

  while(angleDiff(botAngle(facingFront), radiansToDeg(vectorGAngle(target_X, target_Y)), DEGREES) > 5)
  {
    Rot.updateSpeed();
    
    LFM.spin(fwd, Rot.getLPow(), rpm);
    LBM.spin(fwd, Rot.getLPow(), rpm);
    RFM.spin(fwd, Rot.getRPow(), rpm);
    RBM.spin(fwd, Rot.getRPow(), rpm);

    if (timer.getTime() > timeout){
      stopMotors();
      return;
    }

    wait(5, msec);
  }
  stopMotors();
  wait(0.25, sec);


  //------------------------------------------------------------

  PIDClass TPID(PID);
  DriveController drive(target_X, target_Y, TPID, facingFront);
  double lPow;
  double rPow;

  while(vectorLength(target_X, target_Y) > 4)
  {
    drive.updateSpeed();
    rPow = drive.getPow();
    lPow = drive.getPow();
    str8Drive(rPow, lPow, facingFront, initLRot, initRRot);

    LFM.spin(fwd, lPow, rpm);
    LBM.spin(fwd, lPow, rpm);
    RFM.spin(fwd, rPow, rpm);
    RBM.spin(fwd, rPow, rpm);

    if (timer.getTime() > timeout){
      stopMotors();
      return;
    }

    wait(5, msec);
  }

  stopMotors();
}

void GoToStraight(double distance, double PID, double timeout, bool facingFront)
{

  TimeoutClock timer;
  PIDClass TPID(PID);
  DriveController drive(coordFinderX(distance, botAngle(facingFront)), coordFinderY(distance, botAngle(facingFront)), TPID, facingFront);
  double lPow;
  double rPow;
  double initRRot = EncoderR.rotation(deg);
  double initLRot = EncoderL.rotation(deg);

  while(distance - degToIn(std::abs(EncoderR.rotation(deg) - initRRot), 2.75) > 3)
  {
    drive.updateSpeed();
    rPow = drive.getPow();
    lPow = drive.getPow();
    str8Drive(rPow, lPow, facingFront, initLRot, initRRot);

    LFM.spin(fwd, lPow, rpm);
    LBM.spin(fwd, lPow, rpm);
    RFM.spin(fwd, rPow, rpm);
    RBM.spin(fwd, rPow, rpm);

    if (timer.getTime() > timeout){
      stopMotors();
      return;
    }

    wait(10, msec);
  }
  stopMotors();
}

void driveTill(double timeout){
  TimeoutClock timer;
  double lPow = 200;
  double rPow = 200;

  while(Distance.objectDistance(inches) > 3.5)
  {
    //str8Drive(rPow, lPow);

    LFM.spin(fwd, lPow, rpm);
    LBM.spin(fwd, lPow, rpm);
    RFM.spin(fwd, rPow, rpm);
    RBM.spin(fwd, rPow, rpm);

    if (timer.getTime() > timeout){
      stopMotors();
      return;
    }

    wait(5, msec);
  }
  stopMotors();
}

void driveTill(double timeout, double limitX, double limitY, coordType coordinates){
  if (coordinates == RELATIVE){
    limitX += odom.getX();
    limitY += odom.getY();
  }

  TimeoutClock timer;
  double lPow = 200;
  double rPow = 200;

  while(Distance.objectDistance(inches) > 3.5)
  {
    //str8Drive(rPow, lPow);

    LFM.spin(fwd, lPow, rpm);
    LBM.spin(fwd, lPow, rpm);
    RFM.spin(fwd, rPow, rpm);
    RBM.spin(fwd, rPow, rpm);

    if (timer.getTime() > timeout || (std::abs(limitX - odom.getX()) < 2 || std::abs(limitY - odom.getY()) < 2)){
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
void TurnTo(double target_angle, double timeout)
{

  TimeoutClock timer;
  PIDClass RPID(1.15);
  RotationController Rot(target_angle, RPID);

  while(angleDiff(odom.getAngle(DEGREES), target_angle, DEGREES) > 3)
  {
    Rot.updateSpeed();
    
    LFM.spin(fwd, Rot.getLPow(), rpm);
    LBM.spin(fwd, Rot.getLPow(), rpm);
    RFM.spin(fwd, Rot.getRPow(), rpm);
    RBM.spin(fwd, Rot.getRPow(), rpm);

    if (timer.getTime() > timeout)
      break;

    wait(5, msec);
  }
  stopMotors();
}

//This function moves the arm up and down. The arm degree will reset to zero every time the function is called.
//Positive moves the arm up, Negative moves it down.
//If waitForRelease is set to false, the function will start moving the arm and then move on to the next function while still moving the arm.
//Units are in Degrees.

double armPos;

int armMethod(){
  if(armPos > ArmEncoder.rotation(deg)){
    Arm.spin(fwd, 100, pct);
    waitUntil(armPos <= ArmEncoder.rotation(deg));
  }
  else{
    Arm.spin(reverse, 100, pct);
    waitUntil(armPos >= ArmEncoder.rotation(deg));
  }
  Arm.stop(hold);
  return 0;
}

void moveArm (double ArmPos, bool threaded){
  armPos = ArmPos;
  if(threaded){
    task threadArm(armMethod);
  }
  else{
    armMethod();
  }
}

double ringTime;
directionType ringDir;

int ringMethod(){
  RingConveyor.spin(ringDir, 100, rpm);
  wait(ringTime, sec);
  RingConveyor.stop(brake);
  return 0;
}

void moveRings(double time, directionType dir, bool threaded){
  ringTime = time;
  ringDir = dir;
  if(threaded){
    task threadRings(ringMethod);
  }
  else{
    ringMethod();
  }
}

 