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
  move(2, fwd, 1);
  wait(0.25, sec);
  roller();

  //Endgame
  move(10, reverse, 2);
  turnTo(225, 2);
  move(85, fwd, 5);
  wait(0.5, sec);
  turnTo(190, 2);
  Endgame.set(true);

} 