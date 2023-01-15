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
  
  //Roller
  intake(true, reverse);
  move(2, fwd, 1);
  wait(1.25, sec);
  intake(false, reverse);

  //Shoot
  move(1.5, reverse, 1);
  turnTo(170, 2);
  flywheel(true, 350);
  waitUntil((Flywheel1.velocity(rpm) >= 350) || (Flywheel2.velocity(rpm) >= 350));
  wait(0.3, sec);
  shootDisk();
  wait(0.5, sec);
  waitUntil((Flywheel1.velocity(rpm) >= 350) || (Flywheel2.velocity(rpm) >= 350));
  wait(0.3, sec);
  shootDisk();
  wait(0.5, sec);
  flywheel(false, 400);

} 