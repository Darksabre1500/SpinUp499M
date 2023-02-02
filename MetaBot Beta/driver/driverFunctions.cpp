#include "vex.h"

int jValuesLFM;
int jValuesRFM;
int jValuesLBM;
int jValuesRBM;

void drive() {

  //Gathers joystick data from controller and creates speeds for each motor
  jValuesLFM = Controller1.Axis3.position() + Controller1.Axis4.position() + (Controller1.Axis1.position() * 0.8);
  jValuesRFM = Controller1.Axis3.position() - Controller1.Axis4.position() - (Controller1.Axis1.position() * 0.8);
  jValuesLBM = Controller1.Axis3.position() - Controller1.Axis4.position() + (Controller1.Axis1.position() * 0.8);
  jValuesRBM = Controller1.Axis3.position() + Controller1.Axis4.position() - (Controller1.Axis1.position() * 0.8);

  //Tells the motors to spin at their respective values, capping the power at 100%
  LFM.spin(fwd, numCutoff(jValuesLFM, 100), pct);
  RFM.spin(fwd, numCutoff(jValuesRFM, 100), pct);
  LBM.spin(fwd, numCutoff(jValuesLBM, 100), pct);
  RBM.spin(fwd, numCutoff(jValuesRBM, 100), pct);     
} 

void slowTurn(){
  if (Controller1.ButtonY.pressing()){
    LFM.spin(reverse, 15, rpm);
    LBM.spin(reverse, 15, rpm);
    RFM.spin(fwd, 15, rpm);
    RBM.spin(fwd, 15, rpm);
  }
  else if (Controller1.ButtonA.pressing()){
    LFM.spin(fwd, 15, rpm);
    LBM.spin(fwd, 15, rpm);
    RFM.spin(reverse, 15, rpm);
    RBM.spin(reverse, 15, rpm);
  }
}

void brakeWheels() {
  if (LFM.power() == 0 && LFM.power() == 0 && LFM.power() == 0 && LFM.power() == 0){
    LFM.stop(brake);
    RFM.stop(brake);
    LBM.stop(brake);
    RBM.stop(brake);
  }
}


bool autonCalled = false;

void callAuton(){
  if (Controller1.ButtonDown.pressing() && !autonCalled){
    autonomous();
    waitUntil(!Competition.isAutonomous());
    autonCalled = true;
  }
} 

void intake(){
  if (Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing()){
    Intake1.spin(fwd, 25, pct);
    Intake2.spin(fwd, 25, pct);
  }
  else if (Controller1.ButtonR1.pressing()){
    Intake1.spin(fwd, 100, pct);
    Intake2.spin(fwd, 100, pct);
  }
  else if (Controller1.ButtonR2.pressing()) {
    Intake1.spin(reverse, 100, pct);
    Intake2.spin(reverse, 100, pct);
  }
  else {
    Intake1.stop(coast);
    Intake2.stop(coast);
  }
}

bool flywheelActive = false;
int flywheelPower = 500;

void flywheel(){
  //Change Power Presets
  if (Controller1.ButtonUp.pressing()) {
    flywheelPower = 500;
  }
  else if (Controller1.ButtonDown.pressing()) {
    flywheelPower = 460;
  }
  //Increment/Decrement Power
  else if (Controller1.ButtonLeft.pressing()) {
    flywheelPower -= 10;
  }
  else if (Controller1.ButtonRight.pressing()) {
    flywheelPower += 10;
  }

  //Toggle Start Flywheel
  if (Controller1.ButtonL1.pressing() && !flywheelActive){
    Flywheel1.spin(fwd, flywheelPower, rpm);
    Flywheel2.spin(fwd, flywheelPower, rpm);
    waitUntil(!Controller1.ButtonL1.pressing());
    flywheelActive = true;
  }
  //Toggle Stop Flywheel
  else if (Controller1.ButtonL1.pressing() && flywheelActive) {
    Flywheel1.stop(coast);
    Flywheel2.stop(coast);
    waitUntil(!Controller1.ButtonL1.pressing());
    flywheelActive = false;
  }
  //Update Flywheel Power
  else if (flywheelActive){
    Flywheel1.spin(fwd, flywheelPower, rpm);
    Flywheel2.spin(fwd, flywheelPower, rpm);
  }

  //Update Power Readout
  Controller1.Screen.clearLine(1);
  Controller1.Screen.setCursor(1,0);
  Controller1.Screen.print("Flywheel Speed: ");
  Controller1.Screen.print("%d", flywheelPower);
}

void flicker(){
  if (Controller1.ButtonL2.pressing() && flywheelActive){
    Flicker.set(true);
    wait(0.125, sec);
    Flicker.set(false);
  }
}

void endgame(){
  if(Controller1.ButtonB.pressing() && Controller1.ButtonX.pressing()){
    Endgame.set(true);
  }
}
