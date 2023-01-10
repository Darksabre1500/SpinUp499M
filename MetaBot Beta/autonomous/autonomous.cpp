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
  //Shoot Preloads
  flywheel(true, 275);
  waitUntil((Flywheel1.velocity(rpm) >= 250) || (Flywheel2.velocity(rpm) >= 250));
  shootDisk();
  wait(0.5, sec);
  flywheel(true, 300);
  waitUntil((Flywheel1.velocity(rpm) >= 250) || (Flywheel2.velocity(rpm) >= 250));
  shootDisk();
  wait(0.5, sec);
  
  //Pick up Row of Disks
  intake(true, fwd);
  turnTo(45, 2);
  wait(0.25, sec);
  flywheel(false, 275);
  strafe(11, right, 2);
  wait(0.25, sec);
  turnTo(40, 2);
  move(55, fwd, 5);

  //Shoot Disks
  flywheel(true, 225);
  turnTo(120, 2);
  waitUntil((Flywheel1.velocity(rpm) >= 225) || (Flywheel2.velocity(rpm) >= 225));
  shootDisk();
  wait(0.5, sec);
  waitUntil((Flywheel1.velocity(rpm) >= 225) || (Flywheel2.velocity(rpm) >= 225));
  shootDisk();
  wait(0.5, sec);
  waitUntil((Flywheel1.velocity(rpm) >= 225) || (Flywheel2.velocity(rpm) >= 225));
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