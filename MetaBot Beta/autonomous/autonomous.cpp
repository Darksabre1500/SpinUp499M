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
  move(0.5, fwd, 1);
  wait(0.5, sec);
  intake(true, reverse);
  wait(1, sec);
  intake(false, reverse);

  //Shoot
  move(2, reverse, 0.4);
  turnTo(150, 2);
  flywheel(true, 400);
  waitUntil((Flywheel1.velocity(rpm) >= 400) || (Flywheel2.velocity(rpm) >= 400));
  wait(0.3, sec);
  shootDisk();
  wait(0.5, sec);
  waitUntil((Flywheel1.velocity(rpm) >= 400) || (Flywheel2.velocity(rpm) >= 400));
  wait(0.3, sec);
  shootDisk();
  wait(0.5, sec);
  flywheel(false, 400);

} 