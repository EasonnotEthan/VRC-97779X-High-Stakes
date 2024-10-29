using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor RightB;
extern motor RightM;
extern motor RightF;
extern motor LeftF;
extern motor LeftM;
extern motor LeftB;
extern controller Controller1;
extern digital_out mobile;
extern motor Arm;
extern motor intake;
extern inertial Iner;
extern optical Opticaldown;
extern digital_out intakeup;
extern digital_out hang;
extern optical Opticaltop;
extern digital_out top;
extern distance Distance1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );