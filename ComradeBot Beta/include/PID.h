#ifndef PIDClass_h
#define PIDClass_h

class PIDClass {
private:
  double kP = 0;
  double kI = 0;
  double kD = 0;

  double proportional = 0;
  double integral = 0;
  double derivative = 0;

  double proportionalFinal = 0;
  double integralFinal = 0;
  double derivativeFinal = 0;
  
  double previous_error = 0;
  double finalSpeed = 0;

public: 
  void PID(double error);
  void PID(double error, double iLimit);
  void PID(double error, double iLimit, double powLimit);

  PIDClass(){}
  PIDClass(double constP);
  PIDClass(double constP, double constI);
  PIDClass(double constP, double constI, double constD);

  void editConstants(double constP, double constI, double constD);

  double getPow(){
    return finalSpeed;
  }

  //Add outputs for debugging
  void sPrint();
  void fullPrint();

};

#endif