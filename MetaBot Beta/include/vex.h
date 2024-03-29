/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)


#include <iostream>
#include <cmath>
#include <iomanip>

#include "drive.h"
#include "autonomous.h"
#include "PID.h"
#include "odometry.h"
#include "generalFunctions.h"
#include "directionControl.h"
#include "backgroundTasks.h"
#include "vision.h"
#include "graphing.h"

//User Added Stuff---------------------------------------------------------------
  extern competition Competition;
  extern PIDClass PIDcontrol;
  void autonomous();
  void usercontrol();