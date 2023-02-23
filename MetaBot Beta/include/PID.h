#include <string>

#ifndef PID_h
#define PID_h

class PIDClass {
private:
  double P = 0;
  double I = 0;
  double D = 0;

  double proportional = 0;
  double integral = 0;
  double derivative = 0;

  double proportionalFinal = 0;
  double integralFinal = 0;
  double derivativeFinal = 0;
  
  double previous_error = 0;
  double finalOutput = 0;

public: 

  PIDClass();
  PIDClass(double constP, double constI, double constD);

  void updatePID(double error, double outputLimit);
  void updatePID(double error, double outputLimit, double iLimit);

  void setP(double P){
    this->P = P;
  }

  void setI(double I){
    this->I = I;
  }

  void setD(double D){
    this->D = D;
  }

  double getP(){
    return P;
  }

  double getI(){
    return I;
  }

  double getD(){
    return D;
  }

  double getOutput(){
    return finalOutput;
  }

  //Add outputs for debugging
  std::string toStr();
  std::string toStrM();
  std::string toStrL();

};

#endif