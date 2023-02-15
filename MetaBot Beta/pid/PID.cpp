#include "vex.h"
using namespace std;

PIDClass::PIDClass(){
  P = 1;
  I = 0;
  D = 0;
}

PIDClass::PIDClass(double constP, double constI, double constD){
  P = constP;
  I = constI;
  D = constD;
}

void PIDClass::updatePID(double error, double outputLimit) 
{
  proportional = error;

	//Begin summing the errors into the integral term if the error is below a threshold,
	//and reset it if not. This is to prevent the integral from growing too large.
		integral += error;

	//Calculate the derivative by finding the change between the current error and
	//last update's error
	derivative = error - previous_error;

  //Save the previous error for the derivative
	previous_error = error;

	//Combine all the parts of the PID function into the PID algorithm and return the value.
  proportionalFinal = P * proportional;
  integralFinal = I * integral;
  derivativeFinal = D * derivative;

  finalOutput = numCutoff(proportionalFinal + integralFinal + derivativeFinal, outputLimit);
}

void PIDClass::updatePID(double error, double outputLimit, double iLimit) 
{
  proportional = error;

	//Begin summing the errors into the integral term if the error is below a threshold,
	//and reset it if not. This is to prevent the integral from growing too large.
	if(error < iLimit) {
		integral += error;
	}
	else {
		integral = 0;
	}

	//Calculate the derivative by finding the change between the current error and
	//last update's error
	derivative = error - previous_error;

  //Save the previous error for the derivative
	previous_error = error;

	//Combine all the parts of the PID function into the PID algorithm and return the value.
  proportionalFinal = P * proportional;
  integralFinal = I * integral;
  derivativeFinal = D * derivative;

  finalOutput = numCutoff(proportionalFinal + integralFinal + derivativeFinal, outputLimit);
}

template <typename T> std::string to_string(const T& n){
  std::ostringstream stm ;
  stm << n ;
  return stm.str();
}

string PIDClass::toStr(){
   return "Output: " + to_string(finalOutput) + "\n"; 
}

string PIDClass::toStrM(){
   return "P: " + to_string(P) + " | I: " + to_string(I) + " | D: " + to_string(D) + "\n";
}

string PIDClass::toStrL(){
  return "Output: " + to_string(proportional) + " | raw integ: " + to_string(integral) + " | raw deriv: " + to_string(derivative)
   + "\nP: " + to_string(proportionalFinal) + " | I: " + to_string(integralFinal) + " | D: " + to_string(derivativeFinal)
   + "\nSpeed: " + to_string(finalOutput) + "\n";
}