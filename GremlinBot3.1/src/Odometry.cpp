#include "vex.h"

//---------------------Odometry Resources---------------------
//https://www.youtube.com/watch?v=_T6KHywSP58
//http://thepilons.ca/wp-content/uploads/2018/10/Tracking.pdf
//https://www.desmos.com/calculator/gdm0tikj1u
//https://www.desmos.com/calculator/kzog7lvqlu

void Odometry::updateOdom()
{
  //Finds distance traveled since last check and converts it to inches
  double L = degToIn(EncoderL.position(deg) - prevL, 2.75);
  double R = degToIn(EncoderR.position(deg) - prevR, 2.75);
  //Saves Encoder Values for next check
  prevL = EncoderL.position(deg);
  prevR = EncoderR.position(deg);

  //Finds bot's angle of rotation
  double theta = (L-R)/(Wl+Wr);

  double dChord;

  if (theta != 0)
  {
    //Finds vector at the middle of the bot from starting position to ending position
    dChord = 2 * sin(theta/2) * (R/theta + Wr);    
  }
  else 
  {
    //Distance traveled in each direction
    dChord = (L+R)/2;
  }

  //Converts vectors to local x and y deltas
  double dlocalX = dChord * sin(botRot + theta/2);
  double dlocalY = dChord * cos(botRot + theta/2);

  //Adds deltas to previous global coordinates
  globalX += dlocalX;
  globalY += dlocalY;
  //Updates angle of rotation
  botRot += theta;
}

void Odometry::updateAngle()
{
  //Converts angle to have 0 on the x-axis and have counterclockwise be positive
  angleRadUnwrapped = -(botRot - startRot);
  angleRad = angleWrap(angleRadUnwrapped, RADIANS);
  angleDeg = radiansToDeg(angleRad);
}

int odometry(){
  while(true){
  odom.updateOdom();
  odom.updateAngle();
  wait(2, msec);
  }
  return 0;
}