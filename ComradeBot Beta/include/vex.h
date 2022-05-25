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

#include "driveType.h"
#include "autonType.h"
#include "PID.h"
#include "odometryType.h"
#include "General_Functions.h"
#include "Pure_Pursuit.h"
#include "Direction_Control.h"

//User Added Stuff---------------------------------------------------------------
  extern competition Competition;
  extern PIDClass PIDcontrol;
  void autonomous();
  void usercontrol();