#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor LFM = motor(PORT2, ratio18_1, true);
motor LBM = motor(PORT19, ratio18_1, true);
motor RFM = motor(PORT6, ratio18_1, false);
motor RBM = motor(PORT8, ratio18_1, false);
encoder EncoderL = encoder(Brain.ThreeWirePort.G);
encoder EncoderR = encoder(Brain.ThreeWirePort.E);
motor RingConveyor = motor(PORT20, ratio18_1, false);
digital_out FClamp = digital_out(Brain.ThreeWirePort.A);
digital_out BClamp = digital_out(Brain.ThreeWirePort.B);
encoder ArmEncoder = encoder(Brain.ThreeWirePort.C);
motor ArmMotorA = motor(PORT11, ratio36_1, false);
motor ArmMotorB = motor(PORT5, ratio36_1, true);
motor_group Arm = motor_group(ArmMotorA, ArmMotorB);
distance Distance = distance(PORT15);

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