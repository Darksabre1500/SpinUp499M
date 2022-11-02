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
  flywheel(true, 550);
  wait(2.5, sec);
  shootDisk();
  wait(1.2, sec);
  shootDisk();
  wait(1.5, sec);
  flywheel(false, 520);
  moveForward(2.5, 2);
  turnTo(230, 2);
  wait(0.25, sec);
  strafeRight(1, 2);
  moveForward(8.3, 1);
  intake(true, reverse);
  wait(2, sec);
  intake(false, reverse);
  //strafeRight(3, 2);
  //moveForward(5, 2);
  //intake(true, reverse);
  //goTo(3, 10, 2, ABSOLUTE);
  //goTo(0, 12, 2, RELATIVE);
  //turnTo(165, 2);

  /*flywheel(true, 520);
  wait(3, sec);
  shootDisk();
  wait(2, sec);
  shootDisk();*/

  /*flywheel(true, 520);
  wait(2.9, sec);
  shootDisk();
  wait(1.3, sec);
  shootDisk();
  wait(1, sec);
  flywheel(false, 520);*/
} 