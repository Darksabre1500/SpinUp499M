#include "vex.h"

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  BClamp.set(true);
  while (1) {
      drive(); 
      moveArm(); 
      movePistons();
      moveRings();
      //haptics()
      //callAuton();
  }
}