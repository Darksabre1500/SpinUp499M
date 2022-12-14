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
  flywheel(true, 275);
  waitUntil((Flywheel1.velocity(rpm) >= 275) || (Flywheel2.velocity(rpm) >= 275));
  shootDisk();
  wait(0.75, sec);
  shootDisk();
  wait(0.75, sec);
  turnTo(45, 2);
  strafe(9.5, right, 2);
  turnTo(41, 2);
  intake(true, fwd);
  move(55, fwd, 5);
  flywheel(true, 275);
  turnTo(140, 2);
  waitUntil((Flywheel1.velocity(rpm) >= 275) || (Flywheel2.velocity(rpm) >= 275));
  shootDisk();
  wait(0.75, sec);
  shootDisk();
  wait(0.75, sec);
  shootDisk();
  flywheel(false, 275);
  intake(false, fwd);

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