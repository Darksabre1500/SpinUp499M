#include "vex.h"
using namespace std;

PIDClass::PIDClass(double constP){
  kP = constP;
  kI = 0;
  kD = 0;
}

PIDClass::PIDClass(double constP, double constI){
  kP = constP;
  kI = constI;
  kD = 0;
}

PIDClass::PIDClass(double constP, double constI, double constD){
  kP = constP;
  kI = constI;
  kD = constD;
}

void PIDClass::editConstants(double constP, double constI, double constD){
  kP = constP;
  kI = constI;
  kD = constD;
}

void PIDClass::PID(double error) 
{
  double maxValue = 200;

  proportional = error;

	//Calculate the derivative by finding the change between the current error and
	//last update's error
	derivative = error - previous_error;

  //Save the previous error for the derivative
	previous_error = error;

	//Combine all the parts of the PID function into the PID algorithm and return the value.
  proportionalFinal = kP * proportional;
  derivativeFinal = kD * derivative;

  finalSpeed = numCutoff(proportionalFinal + derivativeFinal, maxValue);
}

void PIDClass::PID(double error, double iLimit) 
{
  double maxValue = 200;

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
  proportionalFinal = kP * proportional;
  integralFinal = kI * integral;
  derivativeFinal = kD * derivative;

  finalSpeed = numCutoff(proportionalFinal + integralFinal + derivativeFinal, maxValue);
}

void PIDClass::PID(double error, double iLimit, double powLimit) 
{
  double maxValue = powLimit;

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
  proportionalFinal = kP * proportional;
  integralFinal = kI * integral;
  derivativeFinal = kD * derivative;

  finalSpeed = numCutoff(proportionalFinal + integralFinal + derivativeFinal, maxValue);
}

void PIDClass::sPrint(){
  cout << "Speed: " << finalSpeed << endl; 
}

void PIDClass::fullPrint(){
  cout << "Error: " << proportional << " | raw integ: " << integral << " | raw deriv: " << derivative << endl;
  cout << "P: " << proportionalFinal << " | I: " << integralFinal << " | D: " << derivativeFinal << endl;
  cout << "Speed: " << finalSpeed << endl; 
  cout << endl;
}