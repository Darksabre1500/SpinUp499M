#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LFM = motor(PORT2, ratio18_1, true);
motor LBM = motor(PORT19, ratio18_1, true);
motor RFM = motor(PORT6, ratio18_1, false);
motor RBM = motor(PORT8, ratio18_1, false);
encoder EncoderL = encoder(Brain.ThreeWirePort.G);
encoder EncoderR = encoder(Brain.ThreeWirePort.E);
encoder EncoderS = encoder(Brain.ThreeWirePort.C);
/*vex-vision-config:begin*/
vision Vision = vision (PORT7, 50);
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