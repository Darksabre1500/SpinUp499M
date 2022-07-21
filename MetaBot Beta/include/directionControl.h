#ifndef directionControl_h
#define directionControl_h
#include "PID.h"

extern double Mfl;
extern double Mfr;
extern double Mbl;
extern double Mbr;

void omniController(double targetAngle, double speed);
double turnDistance(double targetAngle);
double vectorRAngle(double endX, double endY);
double vectorGAngle(double endX, double endY);
double vectorLength(double endX, double endY);
double coordFinderX(double distance, double angle);
double coordFinderY(double distance, double angle);

#endif