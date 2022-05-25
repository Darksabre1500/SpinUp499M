#include "vex.h"
using namespace std;

double second = 0;

//Background Tasks
  int tempuatureDisplay() {
    while(true) {
      Brain.Screen.clearLine(1);
      Brain.Screen.clearLine(2);
      Brain.Screen.clearLine(3);
      Brain.Screen.clearLine(4);
      Brain.Screen.clearLine(5);
      Brain.Screen.clearLine(6);
      Brain.Screen.setCursor(1, 1);
      Brain.Screen.print("LFM Temp: %.2f%C", LFM.temperature(celsius));
      Brain.Screen.print(" | RFM Temp: %.2f%C", RFM.temperature(celsius));
      Brain.Screen.setCursor(2, 1);
      Brain.Screen.print("LBM Temp: %.2f%C", LBM.temperature(celsius));
      Brain.Screen.print(" | RBM Temp: %.2f%C", RBM.temperature(celsius));
      Brain.Screen.setCursor(3, 1);
      Brain.Screen.print("Arm Temp: %.2f%C", Arm.temperature(celsius));
      Brain.Screen.print(" | Ring Temp: %.2f%C", RingConveyor.temperature(celsius));
      Brain.Screen.setCursor(4, 1);
      Brain.Screen.print("Battery: ");
      Brain.Screen.print("%d", Brain.Battery.capacity());
      Brain.Screen.setCursor(5, 1);
      Brain.Screen.print("------------------------------------------------");
      wait(5, sec);
    }
    return 0;
  }

  int brainDebug() {
    while(true){
      Brain.Screen.clearLine(6);
      Brain.Screen.clearLine(7);
      Brain.Screen.clearLine(8);
      Brain.Screen.clearLine(9);
      Brain.Screen.clearLine(10);
      Brain.Screen.clearLine(11);
      Brain.Screen.clearLine(12);
      Brain.Screen.setCursor(6, 1);
      Brain.Screen.print("Bot Angle: ");
      Brain.Screen.print("%.2f", odom.getAngle(DEGREES));
      Brain.Screen.setCursor(7, 1);
      Brain.Screen.print("Global X: ");
      Brain.Screen.print("%.2f", odom.getX());
      Brain.Screen.print(" | Global Y: ");
      Brain.Screen.print("%.2f", odom.getY());
      Brain.Screen.setCursor(8, 1);
      Brain.Screen.print("Encoder L: ");
      Brain.Screen.print("%.2f", EncoderL.rotation(deg));
      Brain.Screen.print(" | Encoder R: ");
      Brain.Screen.print("%.2f", EncoderR.rotation(deg));
      Brain.Screen.setCursor(9, 1);
      Brain.Screen.print("Arm Encoder: ");      
      Brain.Screen.print("%.2f", ArmEncoder.rotation(deg));
      Brain.Screen.setCursor(10, 1);
      Brain.Screen.print("Distance :");      
      Brain.Screen.print(" %.2f", Distance.objectDistance(inches));
      wait(100, msec);
    }
    return 0;
  }

  int controllerDebug(){
    while(true){
      if(LFM.temperature(celsius) >= 65 || RFM.temperature(celsius) >= 65 || LBM.temperature(celsius) >= 65 || RBM.temperature(celsius) >= 65) 
      {
        Controller1.Screen.clearLine(1);
        Controller1.Screen.setCursor(1, 1);
        Controller1.Screen.print("Overheating");
        Controller1.rumble("- - -");
        
      }  
      else if (LFM.temperature(celsius) >= 55 || RFM.temperature(celsius) >= 55 || LBM.temperature(celsius) >= 55 || RBM.temperature(celsius) >= 55) 
      {
        Controller1.Screen.clearLine(1);
        Controller1.Screen.setCursor(1, 1);
        Controller1.Screen.print("Throttling");
        Controller1.rumble(". . .");
      }
      else if(Brain.Battery.capacity() < 20){
        Controller1.rumble("-.-.-");
      }
      wait(10, sec);
    }
    return 0;
  }
  
  int TerminalDebug() 
  {
    cout << fixed << setprecision(2);

    while (true) {
      //cout << flipperAngle();
      wait(100, msec);
      cout << RFM.velocity(rpm) << " " << RBM.velocity(rpm) << " " << LFM.velocity(rpm) << " " << LBM.velocity(rpm) << endl;

    }
    return 0;
  }

//  

//Conversions & Value Finders
  

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

  double degToRadians(double deg)
  {
    return deg * M_PI/180;
  }

  double radiansToDeg(double radian)
  {
    return radian * 180/M_PI;
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
    if(sin(degToRadians(target) - degToRadians(actual)) < 0)
      dir = 1;
    return dir * (180 - abs(abs(actual - target) - 180));
  }

  double angleWrap(double angle, angleType aType){
    if (aType == RADIANS)
    { 
      if (angle < 0) 
        angle = fmod(angle, 2 * M_PI) + 2*M_PI;
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
