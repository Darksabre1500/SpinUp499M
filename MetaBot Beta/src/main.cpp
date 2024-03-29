/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Caleb Beversdorf                                          */
/*    Created:      Mon Feb 22 2021                                           */
/*    Description:  X-Drive Bot Code                                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;
using namespace std;
competition Competition;
Odometry odom;


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

}

// Main will set up the competition functions and callbacks.
int main() {

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  Competition.bStopAllTasksBetweenModes = false;
  Competition.bStopTasksBetweenModes = false;  

  // Background Processes
  
  /*
  graph g( 2, 0, 0);
  g.setColor(0, vex::color::white );
  g.setColor(1, vex::color::red );
  thread t1(lineTask, static_cast<void *>(&g));
  thread t2(RPMTask, static_cast<void *>(&g));
  */

  
  Brain.Screen.clearScreen();
  task temps(tempuatureDisplay);
  task brainTB(brainDebug);
  task controllerTB(controllerDebug);
  task updateOdometry(odometry);
  

  Flicker.set(false);
  EncoderL.resetRotation();
  EncoderR.resetRotation();
  EncoderS.resetPosition();

  

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }

  
}
