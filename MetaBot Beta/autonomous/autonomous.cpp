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
  //7 cm setup

  //Flywheel
  flywheel(505);
  wait(0.5, sec);
  
  //Roller
  strafe(1.5, left, 0.75);
  turnTo(110, 1);
  move(15, reverse, 0.75);
  odom.resetAngle();
  move(6, fwd, 2);
  wait(0.1, sec);
  turnTo(0, 2);
  wait(0.1, sec);
  move(24.5, fwd, 2);
  wait(0.1, sec);
  turnTo(270, 2);
  wait(0.1, sec);
  move(8, fwd, 1);
  wait(0.1, sec);
  roller();

} 