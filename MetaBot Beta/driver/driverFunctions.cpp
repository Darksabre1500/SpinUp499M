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

  if (jValuesLFM != 0 || jValuesRFM != 0 || jValuesLBM != 0 || jValuesRBM != 0){
    LFM.spin(fwd, numCutoff(jValuesLFM, 100), pct);
    RFM.spin(fwd, numCutoff(jValuesRFM, 100), pct);
    LBM.spin(fwd, numCutoff(jValuesLBM, 100), pct);
    RBM.spin(fwd, numCutoff(jValuesRBM, 100), pct);
  }      
  else {
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