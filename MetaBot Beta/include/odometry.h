#include <math.h>
#include "generalFunctions.h"

#ifndef odometry_h
#define odometry_h

//Updater for task
int odometry();

//Odometry method
class Odometry{
private:
  //Starting conditions
  const double Wl = 1.945;
  const double Wr = 1.945;
  const double Ws = 4.25;
  const double startRot = degToRad(90);
  const double startX = 0;
  const double startY = 0;

  //Program variables
  double prevL = 0;
  double prevR = 0;
  double prevS = 0;
  double botRot = 0;

  double globalX = startX;
  double globalY = startY;

  double angleRadUnwrapped;
  double angleDeg;
  double angleRad;

  public:

  void updateOdom();
  void updateAngle();

  double getX(){
    return globalX;
  }
  double getY(){
    return globalY;
  }
  double getAngle(angleType aType){
    if (aType == DEGREES)
      return angleDeg;
    else
      return angleRad;
  }
};

//Odom declaration
extern Odometry odom;

#endif