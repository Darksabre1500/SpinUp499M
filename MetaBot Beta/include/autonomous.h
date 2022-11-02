#ifndef auton_h
#define auton_h

#include "drive.h"
using namespace vex;

  enum coordType {ABSOLUTE, RELATIVE};
  
  void stopMotors();
  void goTo(double target_X, double target_Y, double timeout, coordType coordinates);
  void turnTo(double target_angle, double timeout);
  void turnToGoal(colorType goalColor, turnType direction, double timeout);
  void intake(bool turnOn, directionType dir);
  void flywheel(bool turOn, int pow);
  void shootDisk();
  void moveForward(double inches, double timeout);
  void strafeRight(double inches, double timeout);

#endif