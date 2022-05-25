#include "vex.h"

void drive() {
  int rightPow = numCutoff(Controller1.Axis3.position(pct) - Controller1.Axis1.position(pct), 100); 
  int leftPow = numCutoff(Controller1.Axis3.position(pct) + Controller1.Axis1.position(pct), 100);

  if (Controller1.Axis3.position(pct) != 0 || Controller1.Axis1.position(pct) != 0){
    LFM.spin(fwd, leftPow , pct);
    RFM.spin(fwd, rightPow, pct);
    LBM.spin(fwd, leftPow, pct);
    RBM.spin(fwd, rightPow, pct);
  }      
  else {
    LFM.stop(brake);
    RFM.stop(brake);
    LBM.stop(brake);
    RBM.stop(brake);
  }
} 

void moveArm()
{
  if (Controller1.ButtonL1.pressing())
    Arm.spin(fwd, 100, pct);
  else if (Controller1.ButtonL2.pressing())
    Arm.spin(reverse, 100, pct);
  else
    Arm.stop(hold);
}

bool fClampOn;
bool bClampOn;
bool pressingR1;
bool pressingR2;

void movePistons(){
  if (Controller1.ButtonR1.pressing()){
    if(!pressingR1){
      fClampOn = !fClampOn;
      pressingR1 = true;
    }
  }
  else {
    pressingR1 = false;
  }
  if (Controller1.ButtonR2.pressing()){
    if(!pressingR2){
      bClampOn = !bClampOn;
      pressingR2 = true;
    }
  }
  else {
    pressingR2 = false;
  }

  if(fClampOn)
    FClamp.set(false);
  else 
    FClamp.set(true);
  if(bClampOn)
    BClamp.set(true);
  else 
    BClamp.set(false);
}

bool conveyorOn;
bool pressingX;

void moveRings()
{
  if (Controller1.ButtonX.pressing()){
    if(!pressingX){
      conveyorOn = !conveyorOn;
      pressingX = true;
    }
  }
  else {
    pressingX = false;
  }

  if (Controller1.ButtonB.pressing()){
    RingConveyor.spin(reverse, 120, rpm);
  }
  else if (conveyorOn) {
    RingConveyor.spin(fwd, 120, rpm);
  }
  else if (!conveyorOn) {
    RingConveyor.stop(brake);
  }
}

bool interrupted;

void haptics(){
  if (Distance.objectDistance(inches) < 3.5 && interrupted == false){
    Controller1.rumble("-");
    interrupted = true;
  }
  else if (Distance.objectDistance(inches) > 3.5 && interrupted == true) {
    interrupted = false;
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