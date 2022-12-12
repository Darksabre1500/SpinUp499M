#include "vex.h"

#include "vex.h"

double Mfl;
double Mfr;
double Mbl;
double Mbr;

//https://www.desmos.com/calculator/dadgckbr1z

void omniController(double targetAngle, double speed)
{
  //T finds Direction to move, R finds how much to prioritize rotation, and S finds speed
  double T = angleWrap(targetAngle - odom.getAngle(RADIANS) + M_PI/2, RADIANS);
  double R = 0;
  double S = numCutoff(speed/200, 1);

  //Power of each diagonal
  double P1 = -cos(T + (M_PI/4));
  double P2 = sin(T + (M_PI/4));

  //Ratio for speed
  double Sr = std::max(std::abs(P1), std::abs(P2)) / S;

  //Motor power calculations
  Mfl = P2/Sr * (1-std::abs(R)) + R*S;
  Mfr = P1/Sr * (1-std::abs(R)) - R*S;
  Mbl = P1/Sr * (1-std::abs(R)) + R*S;
  Mbr = P2/Sr * (1-std::abs(R)) - R*S;

  //Scales power for motor rpm
  Mfl *= 200;
  Mfr *= 200;
  Mbl *= 200;
  Mbr *= 200;

}

double turnDistance(double targetAngle)
{
  //Positive is counterclockwise, negative is clockwise
  double dir = 1;
  if(sin(degToRad(targetAngle) - odom.getAngle(RADIANS)) < 0)
    dir = -1;
    
  return dir * angleDiff(odom.getAngle(DEGREES), targetAngle, DEGREES);
}

//https://www.youtube.com/watch?v=3l7ZNJ21wMo

double vectorRAngle(double endX, double endY)
{
  double gAngle = vectorGAngle(endX, endY);
  //Finds angle from 0 - 2pi of the bot angle from the vector angle
  double relativeAngle = angleWrap(gAngle - odom.getAngle(RADIANS), RADIANS);

  return relativeAngle;
}

double vectorGAngle(double endX, double endY)
{
  //Finds X and Y difference from start to target
  double vectorX = endX-odom.getX();
  double vectorY = endY-odom.getY();

  //Finds angle from 0 - 2pi of the vector from 0 (right on the x-axis)
  double vectorGlobalAngle = angleWrap(atan2(vectorY, vectorX), RADIANS);

  return vectorGlobalAngle;
}


double vectorLength(double endX, double endY)
{
  //Finds X and Y difference from start to target
  double vectorX = endX-odom.getX();
  double vectorY = endY-odom.getY();
  
  //Finds length of the vector
  double vectorL = hypot(vectorX, vectorY);

  return vectorL;
}

double coordFinderX(double distance, double angle){
  return odom.getX() + (distance * cos(angle)); 
}

double coordFinderY(double distance, double angle){
  return odom.getY() + (distance * sin(angle)); 
}