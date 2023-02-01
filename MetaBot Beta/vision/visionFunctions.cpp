#include "vex.h"

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


