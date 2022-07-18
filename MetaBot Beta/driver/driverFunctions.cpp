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
    LFM.spin(fwd, pow, pct);
    RFM.spin(reverse, pow, pct);
    LBM.spin(fwd, pow, pct);
    RBM.spin(reverse, pow, pct);
  }
  else if (pos < 152 && pos > 0) {
    pow = (157.0 - pos) / 2;
    LFM.spin(reverse, pow, pct);
    RFM.spin(fwd, pow, pct);
    LBM.spin(reverse, pow, pct);
    RBM.spin(fwd, pow, pct);
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


bool called = false;

void callAuton(){
  if (Controller1.ButtonDown.pressing() && !called){
    autonomous();
    waitUntil(!Competition.isAutonomous());
    called = true;
  }
} 
