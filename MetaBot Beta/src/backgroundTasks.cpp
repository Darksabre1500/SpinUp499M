#include "vex.h"
using namespace std;

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
    Brain.Screen.print("Intake1 Temp: %.2f%C", Intake1.temperature(celsius));
    Brain.Screen.print(" | Intake2 Temp: %.2f%C", Intake2.temperature(celsius));
    Brain.Screen.setCursor(4, 1);
    Brain.Screen.print("Flywheel1 Temp: %.2f%C", Intake1.temperature(celsius));
    Brain.Screen.print(" | Flywheel2 Temp: %.2f%C", Intake2.temperature(celsius));
    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print("Battery: ");
    Brain.Screen.print("%d", Brain.Battery.capacity());
    Brain.Screen.setCursor(6, 1);
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
    Brain.Screen.setCursor(7, 1);
    Brain.Screen.print("Bot Angle: ");
    Brain.Screen.print("%.2f", odom.getAngle(DEGREES));
    Brain.Screen.print(" | %.5f", odom.getAngle(RADIANS));
    Brain.Screen.setCursor(8, 1);
    Brain.Screen.print("Global X: ");
    Brain.Screen.print("%.2f", odom.getX());
    Brain.Screen.print(" | Global Y: ");
    Brain.Screen.print("%.2f", odom.getY());
    Brain.Screen.setCursor(9, 1);
    Brain.Screen.print("Encoder L: ");
    Brain.Screen.print("%.2f", EncoderL.rotation(deg));
    Brain.Screen.print(" | Encoder R: ");
    Brain.Screen.print("%.2f", EncoderR.rotation(deg));
    Brain.Screen.setCursor(10, 1);
    Brain.Screen.print("Encoder S: ");      
    Brain.Screen.print("%.2f", EncoderS.position(deg));
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

void RPMTask(void *arg) {
  if( arg == NULL ) return;

  graph *g = static_cast<graph *>(arg);

  while (1){
    g->addPoint(1, 240 - static_cast<int>((avgRPM()/600) * 240));
    this_thread::sleep_for(10);
  }
}

int lineTask(void *arg){
  if( arg == NULL ) return 0;

  graph *g = static_cast<graph *>(arg);

  while(1) {
    g->addPoint(0, 240 - static_cast<int>((490.0/600) * 240));
    this_thread::sleep_for(10);
  }
}