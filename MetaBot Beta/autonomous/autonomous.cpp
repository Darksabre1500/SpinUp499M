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
  flywheel(true, 460);
  waitUntil((Flywheel1.velocity(rpm) >= 460) || (Flywheel2.velocity(rpm) >= 460));
  wait(0.3, sec);
  shootDisk();
  wait(0.5, sec);
  flywheel(true, 460);
  waitUntil((Flywheel1.velocity(rpm) >= 460) || (Flywheel2.velocity(rpm) >= 460));
  wait(0.3, sec);
  shootDisk();
  wait(0.5, sec);
  
  //Roller
  flywheel(false, 420);
  moveForward(2.5, 2);
  turnTo(235, 2);
  wait(0.25, sec);
  strafeRight(8, 2);
  wait(0.25, sec);
  moveForward(8.5, 2);
  wait(0.5, sec);
  intake(true, reverse);
  wait(2, sec);
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