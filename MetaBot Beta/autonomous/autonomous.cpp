#include "vex.h"

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  LFM.spin(fwd, 200, rpm);
  LBM.stop(coast);
  RFM.stop(coast);
  RBM.spin(fwd, 200, rpm);

  //Shoot into Bottom
  /*flywheel(true, 375);
  waitUntil((Flywheel1.velocity(rpm) >= 375) || (Flywheel2.velocity(rpm) >= 375));
  wait(0.5, sec);
  shootDisk();
  wait(0.5, sec);
  waitUntil((Flywheel1.velocity(rpm) >= 375) || (Flywheel2.velocity(rpm) >= 375));
  wait(0.5, sec);
  shootDisk();
  wait(0.5, sec);
  flywheel(false, 375);*/

  //Do Roller
  /*strafe(1.5, right, 2);
  move(10, reverse, 2);
  turnTo(180, 2);
  wait(0.25, sec);
  move(3, fwd, 1);
  intake(true, reverse);
  wait(2, sec);
  intake(false, reverse);*/

} 