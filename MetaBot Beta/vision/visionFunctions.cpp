#include "vex.h"

colorType colorFinder(){
  Vision.takeSnapshot(Vision__REDROLLER);
  double redArea = Vision.largestObject.height * Vision.largestObject.width;
  Vision.takeSnapshot(Vision__BLUEROLLER);
  double blueArea = Vision.largestObject.height * Vision.largestObject.width;

  if (redArea > blueArea){
    return RED;
  }
  else {
    return BLUE;
  }
}

bool isRollerScored(colorType rollerColor) {

  if (rollerColor == BLUE){
    Vision.takeSnapshot(Vision__REDROLLER);
  }
  else{
    Vision.takeSnapshot(Vision__BLUEROLLER);
  }
  
  if (!Vision.largestObject.exists){
    return true;
  }
  else if ((Vision.largestObject.height * Vision.largestObject.width) < 20){
    return true;
  }
  else
    return false;
}


