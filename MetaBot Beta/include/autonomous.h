#ifndef auton_h
#define auton_h

  enum coordType {ABSOLUTE, RELATIVE};
  void stopMotors();
  void goTo(double target_X, double target_Y, double timeout, coordType coordinates);
  void turnTo(double target_angle, double timeout);

#endif