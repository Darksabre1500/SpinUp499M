#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LFM = motor(PORT17, ratio18_1, true);
motor LBM = motor(PORT10, ratio18_1, false);
motor RFM = motor(PORT11, ratio18_1, false);
motor RBM = motor(PORT1, ratio18_1, true);
encoder EncoderL = encoder(Brain.ThreeWirePort.G);
encoder EncoderR = encoder(Brain.ThreeWirePort.E);
/*vex-vision-config:begin*/
signature Vision__REDGOAL = signature (1, 5401, 8037, 6720, -1391, -435, -912, 2.5, 0);
signature Vision__BLUEGOAL = signature (2, -2667, -1837, -2252, 5009, 7089, 6050, 2, 0);
vision Vision = vision (PORT18, 50, Vision__REDGOAL, Vision__BLUEGOAL);
/*vex-vision-config:end*/
motor Intake1 = motor(PORT5, ratio18_1, false);
motor Flywheel1 = motor(PORT14, ratio6_1, true);
motor Flywheel2 = motor(PORT16, ratio6_1, true);
motor Intake2 = motor(PORT6, ratio18_1, false);
digital_out Flicker = digital_out(Brain.ThreeWirePort.A);
rotation EncoderS = rotation(PORT20, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}