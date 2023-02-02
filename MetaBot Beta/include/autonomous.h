#ifndef auton_h
#define auton_h

#include "vision.h"
#include "drive.h"
using namespace vex;

  enum coordType {ABSOLUTE, RELATIVE};
  
  void stopMotors();
  void goTo(double target_X, double target_Y, double timeout, coordType coordinates);
  void turnTo(double target_angle, double timeout);
  void intake(bool turnOn, directionType dir);
  void flywheel(bool turOn, int pow);
  void shootDisk();
  void move(double inches, directionType dir, double timeout);
  void strafe(double inches, turnType dir, double timeout);
  void roller(colorType rollerColor);
  void roller();

#endif