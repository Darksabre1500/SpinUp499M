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

/*
Flipper Vals : -14 rev from purpendicular line start
1.25 for picking back up

*/

void autonomous(void) {
  /*GoToStraight(42, 8, 5, true);
  wait(0.25, sec);
  FClamp.set(false);
  wait(0.25, sec);
  moveArm(3, true);
  GoToStraight(30, 8, 5, false);*/

  //Setup Bot to the left of yellow goal

  GoToStraight(43, 7, 5, true);
  wait(0.4, sec);
  FClamp.set(false);
  wait(0.25, sec);
  moveArm(7, true);
  GoToStraight(10, 7, 5, false);
  TurnTo(55, 3);
  wait(0.25, sec);
  GoToStraight(17, 7, 7, false);
  FClamp.set(true);
  wait(0.25, sec);
  GoToStraight(17, 4, 7, false);
  TurnTo(190, 3);
  wait(0.25, sec);
  GoToStraight(11, 4, 2, false);
  wait(0.25, sec);
  BClamp.set(true);
  moveRings(3, fwd, true);
  GoToStraight(5, 5, 2, true);

} 