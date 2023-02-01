using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern motor LFM;
extern motor LBM;
extern motor RFM;
extern motor RBM;
extern encoder EncoderL;
extern encoder EncoderR;
extern signature Vision__REDROLLER;
extern signature Vision__BLUEROLLER;
extern signature Vision__SIG_3;
extern signature Vision__SIG_4;
extern signature Vision__SIG_5;
extern signature Vision__SIG_6;
extern signature Vision__SIG_7;
extern vision Vision;
extern motor Intake1;
extern motor Flywheel1;
extern motor Flywheel2;
extern motor Intake2;
extern digital_out Flicker;
extern rotation EncoderS;
extern digital_out Endgame;
extern distance Distance;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );