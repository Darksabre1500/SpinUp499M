#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LFM = motor(PORT11, ratio18_1, true);
motor LBM = motor(PORT15, ratio18_1, true);
motor RFM = motor(PORT19, ratio18_1, false);
motor RBM = motor(PORT16, ratio18_1, false);
encoder EncoderL = encoder(Brain.ThreeWirePort.C);
encoder EncoderR = encoder(Brain.ThreeWirePort.A);
encoder EncoderS = encoder(Brain.ThreeWirePort.E);
/*vex-vision-config:begin*/
vision Vision = vision (PORT18, 50);
/*vex-vision-config:end*/

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