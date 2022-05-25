using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern controller Controller2;
extern motor LFM;
extern motor LBM;
extern motor RFM;
extern motor RBM;
extern encoder EncoderL;
extern encoder EncoderR;
extern motor RingConveyor;
extern digital_out FClamp;
extern digital_out BClamp;
extern encoder ArmEncoder;
extern motor_group Arm;
extern distance Distance;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );