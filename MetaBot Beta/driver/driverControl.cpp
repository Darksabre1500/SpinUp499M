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
  while (1) {
    brakeWheels();
    drive();

    //if (Controller1.ButtonB.pressing()){
      aimbot(RED);
    //}

    wait(25, msec);
  }
}