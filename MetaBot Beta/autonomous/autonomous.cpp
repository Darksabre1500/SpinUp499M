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
  //Flywheel
  flywheel(505);
  wait(0.5, sec);
  
  //Roller
  strafe(1.5, right, 0.75);
  turnTo(73, 1);
  move(15, reverse, 0.75);
  wait(0.1, sec);
  odom.resetAngle();
  move(6, fwd, 2);
  wait(0.1, sec);
  turnTo(180, 2);
  wait(0.1, sec);
  move(12, fwd, 2);
  wait(0.1, sec);
  turnTo(270, 2);
  wait(0.1, sec);
  move(7, fwd, 1);
  roller();
} 