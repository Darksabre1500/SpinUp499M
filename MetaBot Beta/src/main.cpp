// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LFM                  motor         17              
// LBM                  motor         10              
// RFM                  motor         11              
// RBM                  motor         1               
// EncoderL             encoder       G, H            
// EncoderR             encoder       E, F            
// Vision               vision        18              
// Intake1              motor         5               
// Flywheel1            motor         14              
// Flywheel2            motor         16              
// Intake2              motor         6               
// Flicker              digital_out   A               
// EncoderS             rotation      20              
// Endgame              digital_out   B               
// ---- END VEXCODE CONFIGURED DEVICES ----
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
