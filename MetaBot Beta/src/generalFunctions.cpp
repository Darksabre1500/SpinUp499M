#include "vex.h"
using namespace std; 
  
  
double inToRev(double inchesTraveled, double wheelDiameter){
  return inchesTraveled / (wheelDiameter * M_PI); 
}

double inToDeg(double inchesTraveled, double wheelDiameter){
  return (inchesTraveled / (wheelDiameter * M_PI)) * 360; 
}

double degToRev(double degreesTraveled) {
  return degreesTraveled / 360; 
}

double degToIn(double degreesTraveled, double wheelDiameter) {
  return (degreesTraveled / 360) * (wheelDiameter * M_PI); 
}

double numCutoff(double num, double cutoff){
  if (num > cutoff)
    num = cutoff;
  else if (num < -cutoff)
    num = -cutoff;
  return num;
}

double degToRad(double deg)
{
  return deg * (M_PI/180.0);
}

double radToDeg(double radian)
{
  return radian * (180.0/M_PI);
}

double numberDiff(double actual, double target)
{
  return abs(target-actual);
}

double angleDiff(double actual, double target, angleType aType)
{
  return 180 - abs(abs(actual - target) - 180);
}

double angleDiffDir(double actual, double target)
{
  int dir = -1;
  if(sin(degToRad(target) - degToRad(actual)) < 0)
    dir = 1;
  return dir * (180 - abs(abs(actual - target) - 180));
}

double angleWrap(double angle, angleType aType){
  if (aType == RADIANS)
  { 
    if (angle < 0) 
      angle = fmod(angle, 2 * M_PI) + 2 * M_PI;
    else
      angle = fmod(angle, 2 * M_PI);
  }
  else if (aType == DEGREES) 
  {
    if (angle < 0) 
      angle = fmod(angle, 360) + 360;
    else
      angle = fmod(angle, 360); 
  }  
  return angle;
}
