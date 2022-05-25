#ifndef Direction_Control_h
#define Direction_Control_h
#include "PID.h"

void str8Drive(double &initRPow, double &initLPow, bool fwd, double initLEnc, double initREnc);

class RotationController{
private:
  double targetAngle = 0;
  double lSpeed = 0;
  double rSpeed = 0;
  PIDClass RPID;
  
public:
  RotationController(double targetAngle, PIDClass &PID){
    this->targetAngle = targetAngle;
    RPID = PID;
  }

  void setAngle(double angle){
    targetAngle = angle;
  }

  void updateSpeed();

  double getLPow(){
    return lSpeed;
  }
  double getRPow(){
    return rSpeed;
  }
};

class DriveController{
private:
  bool forward;
  
  double speed = 0;
  double targetX;
  double targetY;

  PIDClass TPID;


public:
 
  DriveController(double targetX, double targetY, PIDClass &PID1);
  DriveController(double targetX, double targetY, PIDClass &PID1, bool forward);

  void updateSpeed();

  double getPow(){
    return speed;
  }
};

#endif