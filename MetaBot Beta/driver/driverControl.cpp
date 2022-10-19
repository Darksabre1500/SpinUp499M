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
    intake();
    task fly(flywheel);
    task flick(flicker);

    /*if (Controller1.ButtonA.pressing()){
      aimbot(BLUE);
    }*/

    wait(5, msec);
  }
}