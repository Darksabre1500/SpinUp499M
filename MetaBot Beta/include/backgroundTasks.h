#ifndef backgroundTasks_h
#define backgroundTasks_h
#include "robot-config.h"
using namespace vex;

//Functions--------------------------------------------------------------------
int tempuatureDisplay();
int brainDebug();
int controllerDebug();
void RPMTask(void *arg);
int lineTask(void *arg);

#endif