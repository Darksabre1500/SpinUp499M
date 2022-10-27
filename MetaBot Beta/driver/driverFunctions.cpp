#include "vex.h"

int jValuesLFM;
int jValuesRFM;
int jValuesLBM;
int jValuesRBM;

void drive() {

  jValuesLFM = Controller1.Axis3.position() + Controller1.Axis4.position() + (Controller1.Axis1.position() * 0.8);
  jValuesRFM = Controller1.Axis3.position() - Controller1.Axis4.position() - (Controller1.Axis1.position() * 0.8);
  jValuesLBM = Controller1.Axis3.position() - Controller1.Axis4.position() + (Controller1.Axis1.position() * 0.8);
  jValuesRBM = Controller1.Axis3.position() + Controller1.Axis4.position() - (Controller1.Axis1.position() * 0.8);

  LFM.spin(fwd, numCutoff(jValuesLFM, 100), pct);
  RFM.spin(fwd, numCutoff(jValuesRFM, 100), pct);
  LBM.spin(fwd, numCutoff(jValuesLBM, 100), pct);
  RBM.spin(fwd, numCutoff(jValuesRBM, 100), pct);     
} 

void aimbot(colorType goalColor){
  int pos = 0;
  double pow = 0;

  if (goalColor == RED){
    pos = redGoalCenter();
  }
  else{
    pos = blueGoalCenter();
  }

  if (pos > 163){
    pow = (pos - 158.0) / 2;
    LFM.spin(fwd, numCutoff(jValuesLFM + pow, 100), pct);
    RFM.spin(fwd, numCutoff(jValuesRFM - pow, 100), pct);
    LBM.spin(fwd, numCutoff(jValuesLBM + pow, 100), pct);
    RBM.spin(fwd, numCutoff(jValuesRBM - pow, 100), pct);  
  }
  else if (pos < 152 && pos > 0) {
    pow = (157.0 - pos) / 2;
    LFM.spin(fwd, numCutoff(jValuesLFM - pow, 100), pct);
    RFM.spin(fwd, numCutoff(jValuesRFM + pow, 100), pct);
    LBM.spin(fwd, numCutoff(jValuesLBM - pow, 100), pct);
    RBM.spin(fwd, numCutoff(jValuesRBM + pow, 100), pct);  
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
  if (Controller1.ButtonR1.pressing()){
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

int flywheel(){
  //Change Power 
  if (Controller1.ButtonUp.pressing() && flywheelActive){
    flywheelPower = 500;
    Flywheel1.spin(fwd, flywheelPower, rpm);
    Flywheel2.spin(fwd, flywheelPower, rpm);
  }
  else if (Controller1.ButtonUp.pressing() && !flywheelActive) {
    flywheelPower = 500;
  }
  else if (Controller1.ButtonDown.pressing() && flywheelActive) {
    flywheelPower = 420;
    Flywheel1.spin(fwd, flywheelPower, rpm);
    Flywheel2.spin(fwd, flywheelPower, rpm);
  }
  else if (Controller1.ButtonDown.pressing() && !flywheelActive) {
    flywheelPower = 420;
  }

  if (Controller1.ButtonLeft.pressing() && flywheelActive) {
    flywheelPower -= 10;
    Flywheel1.spin(fwd, flywheelPower, rpm);
    Flywheel2.spin(fwd, flywheelPower, rpm);
    Controller1.Screen.clearLine(1);
    Controller1.Screen.setCursor(1,0);
    Controller1.Screen.print("Flywheel Speed: ");
    Controller1.Screen.print("%d", flywheelPower);
    waitUntil(!Controller1.ButtonLeft.pressing());
  }
  else if (Controller1.ButtonLeft.pressing() && !flywheelActive) {
    flywheelPower -= 10;
    Controller1.Screen.clearLine(1);
    Controller1.Screen.setCursor(1,0);
    Controller1.Screen.print("Flywheel Speed: ");
    Controller1.Screen.print("%d", flywheelPower);
    waitUntil(!Controller1.ButtonLeft.pressing());
  }
  else if (Controller1.ButtonRight.pressing() && flywheelActive) {
    flywheelPower += 10;
    Flywheel1.spin(fwd, flywheelPower, rpm);
    Flywheel2.spin(fwd, flywheelPower, rpm);
    Controller1.Screen.clearLine(1);
    Controller1.Screen.setCursor(1,0);
    Controller1.Screen.print("Flywheel Speed: ");
    Controller1.Screen.print("%d", flywheelPower);
    waitUntil(!Controller1.ButtonRight.pressing());
  }
  else if (Controller1.ButtonRight.pressing() && !flywheelActive) {
    flywheelPower += 10;
    Controller1.Screen.clearLine(1);
    Controller1.Screen.setCursor(1,0);
    Controller1.Screen.print("Flywheel Speed: ");
    Controller1.Screen.print("%d", flywheelPower);
    waitUntil(!Controller1.ButtonRight.pressing());
  }

  /*else if (Controller1.ButtonLeft.pressing() && flywheelActive) {
    flywheelPower = 460;
    Flywheel1.spin(fwd, flywheelPower, rpm);
    Flywheel2.spin(fwd, flywheelPower, rpm);
  }
  else if (Controller1.ButtonLeft.pressing() && !flywheelActive) {
    flywheelPower = 460;
  }*/

  //Start Flywheel

  if (Controller1.ButtonL1.pressing() && !flywheelActive){
    Flywheel1.spin(fwd, flywheelPower, rpm);
    Flywheel2.spin(fwd, flywheelPower, rpm);
    waitUntil(!Controller1.ButtonL1.pressing());
    flywheelActive = true;
  }
  else if (Controller1.ButtonL1.pressing() && flywheelActive) {
    Flywheel1.stop(coast);
    Flywheel2.stop(coast);
    waitUntil(!Controller1.ButtonL1.pressing());
    flywheelActive = false;
  }

  

  return 0;
}

int flicker(){
  if (Controller1.ButtonL2.pressing() && flywheelActive){
    Flicker.set(true);
    wait(0.125, sec);
    Flicker.set(false);
  }
  return 0;
}