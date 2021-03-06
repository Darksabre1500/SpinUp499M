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
  PIDClass Speed(15);

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
  PIDClass Speed(1.15);

  while(angleDiff(odom.getAngle(DEGREES), targetAngle, DEGREES) > 3)
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


//This function turns the bot to the specified goal.
//If the goal is not in sight, it will turn the direction specified until it finds the goal.
void turnToGoal(colorType goalColor, turnType direction, double timeout)
{
  TimeoutClock timer;
  PIDClass Speed(0.75);
  int pos;
  directionType dir = fwd;
  if (direction == right)
    dir = reverse;

  do{
    if (goalColor == RED){
      pos = redGoalCenter() - 158;
      if(redGoalCenter() == -1){
        LFM.spin(dir, -200, rpm);
        RFM.spin(dir, 200, rpm);
        LBM.spin(dir, -200, rpm);
        RBM.spin(dir, 200, rpm);
        continue;
      }
    }
    else{
      pos = blueGoalCenter() - 158;
      if(blueGoalCenter() == -1){
        LFM.spin(dir, -200, rpm);
        RFM.spin(dir, 200, rpm);
        LBM.spin(dir, -200, rpm);
        RBM.spin(dir, 200, rpm);
        continue;
      }
    }
    
    Speed.PID(pos, 200);
    LFM.spin(reverse, Speed.getPow(), rpm);
    RFM.spin(reverse, Speed.getPow(), rpm);
    LBM.spin(fwd, Speed.getPow(), rpm);
    RBM.spin(fwd, Speed.getPow(), rpm);

    if (timer.getTime() > timeout)
      break;

    wait(5, msec);

  } while(pos > 2 || pos < -2);
  
  stopMotors();
}