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
  flywheel(true, 500);
  waitUntil((Flywheel1.velocity(rpm) >= 500) || (Flywheel2.velocity(rpm) >= 500));
  shootDisk();
  wait(0.5, sec);
  flywheel(true, 490);
  waitUntil((Flywheel1.velocity(rpm) <= 490) || (Flywheel2.velocity(rpm) <= 490));
  shootDisk();
  wait(0.5, sec);
  
  //Roller
  flywheel(false, 420);
  strafe(1.5, right, 0.75);
  turnTo(70, 1);
  move(15, reverse, 0.75);
  odom.resetAngle();
  move(8, fwd, 2);
  wait(0.25, sec);
  turnTo(270, 2);
  wait(0.25, sec);
  strafe(13, right, 2);
  wait(0.25, sec);
  turnTo(267, 2);
  wait(0.25, sec);
  intake(true, reverse);
  move(7.5, fwd, 2);
  wait(0.5, sec);
  intake(false, reverse);


  /*flywheel(true, 520);
  wait(2.9, sec);
  shootDisk();
  wait(1.3, sec);
  shootDisk();
  wait(1, sec);
  flywheel(false, 520);*/


  //waitUntil((Flywheel1.velocity(rpm) >= 520) || (Flywheel2.velocity(rpm) >= 520));
  /*
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
  */ 

} 