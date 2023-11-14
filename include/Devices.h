#include "vex.h"


// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftMotorA = motor(PORT4, ratio6_1, true);//20
motor leftMotorB = motor(PORT5, ratio6_1, true);//19
motor leftMotorC = motor(PORT6, ratio6_1, true);//15
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB, leftMotorC);

motor rightMotorA = motor(PORT18, ratio6_1, false);
motor rightMotorB = motor(PORT19, ratio6_1, false);
motor rightMotorC = motor(PORT20, ratio6_1, false);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB, rightMotorC);

inertial DrivetrainInertial = inertial(PORT3);

smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 299.24, 320, 40, mm, 1);

motor RecolectorMotorA = motor(PORT12, ratio36_1, false);
motor RecolectorMotorB = motor(PORT13, ratio36_1, true);
motor_group Recolector = motor_group(RecolectorMotorA, RecolectorMotorB);

motor LanzadorMotorA = motor(PORT9, ratio6_1, false);
motor LanzadorMotorB = motor(PORT10, ratio6_1, true);
motor LanzadorMotorC = motor(PORT1, ratio6_1, true);// izq
motor LanzadorMotorD = motor(PORT2, ratio6_1, false);//izq
motor_group Lanzador = motor_group(LanzadorMotorA, LanzadorMotorB, LanzadorMotorC, LanzadorMotorD);

//motor LanzadorMotorA = motor(PORT5, ratio6_1, false);
//motor LanzadorMotorB = motor(PORT14, ratio6_1, false);
//motor Lanzador2MotorA = motor(PORT7, ratio6_1, true);// izq
//motor Lanzador2MotorB = motor(PORT16, ratio6_1, true);//izq
//motor_group Lanzador2 = motor_group(Lanzador2MotorA, Lanzador2MotorB);

controller Controller1 = controller(primary);

bumper Bumper1 = bumper(Brain.ThreeWirePort.H);

//Expansor
digital_out Barra = digital_out(Brain.ThreeWirePort.A);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}