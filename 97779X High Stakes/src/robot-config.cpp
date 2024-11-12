#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor RightB = motor(PORT13, ratio6_1, false);
motor RightM = motor(PORT12, ratio6_1, false); 
motor RightF = motor(PORT11, ratio6_1, false);
motor LeftF = motor(PORT18, ratio6_1, true);
motor LeftM = motor(PORT19, ratio6_1, true);
motor LeftB = motor(PORT20, ratio18_1, true);
controller Controller1 = controller(primary);
digital_out mobile = digital_out(Brain.ThreeWirePort.A);
motor Arm = motor(PORT10, ratio18_1, false);
motor intake = motor(PORT9, ratio18_1, false);
inertial Iner = inertial(PORT3);
//optical Opticaldown = optical(PORT2);
digital_out intakeup = digital_out(Brain.ThreeWirePort.B);
digital_out hang = digital_out(Brain.ThreeWirePort.C);
distance Distance1 = distance(PORT1);
//digital_out top = digital_out(Brain.ThreeWirePort.D);

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