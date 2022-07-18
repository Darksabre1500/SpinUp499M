#include "vex.h"

int redGoalCenter() {
  Vision.takeSnapshot(Vision__REDGOAL);
  if (Vision.objectCount > 0) {
    return Vision.largestObject.centerX;
  } 
  else {
    return -1;
  }
}

int blueGoalCenter() {
  Vision.takeSnapshot(Vision__BLUEGOAL);
  if (Vision.objectCount > 0) {
    return Vision.largestObject.centerX;
  } 
  else {
    return -1;
  }
}
