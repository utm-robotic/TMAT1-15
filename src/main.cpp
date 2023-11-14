/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    20, 15, 13, 11, 4
// Recolector           motor_group   6, 8            
// Lanzador             motor_group   5, 7            
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "Fuctions.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  //DrivetrainInertial.setRotation(42, deg);
  recolectar(21);
  avanzar(2, 75, 60);
  giroR(-42, 5);
  DrivetrainInertial.calibrate();
  wait(1,sec);
  Barra.set(1);
  cruzar();
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  Recolector.setPosition(0, deg);
  Lanzador.setVelocity(100,pct);
  //Lanzador2.setVelocity(100,pct);
  Recolector.setVelocity(100,pct);
  while (1) {
    Brain.Screen.printAt(1, 100, "%f",Recolector.position(deg));

    LeftDriveSmart.spin(reverse, (Controller1.Axis2.value()/127) *100, percent);
    RightDriveSmart.spin(reverse,(Controller1.Axis3.value()/127) * 100,percent);
    
    if(Bumper1.value() == true){
      Recolector.setPosition(0, deg);
    }
    if(Controller1.ButtonL1.pressing()){
      Lanzador.spin(forward);
      //Lanzador2.spin(forward);
    }
    else if (Controller1.ButtonL2.pressing()) {
      Lanzador.spin(reverse);
      //Lanzador2.spin(reverse);
    }
    else if(Controller1.ButtonA.pressing()){
      Lanzador.stop(brake);
      //Lanzador2.stop(brake);
    }

    if(Controller1.ButtonUp.pressing()){
      Recolector.spin(fwd);
      //waitUntil(Bumper1.value() == true);
    }
    else if(Controller1.ButtonDown.pressing()){
      Recolector.spin(reverse);
    }
    else{
      Recolector.stop(hold);
    }

    if(Controller1.ButtonY.pressing()){
      Barra.set(1);
      wait(0.2,sec);
    }
    else if(Controller1.ButtonB.pressing()){
      Barra.set(0);
      wait(0.2,sec);
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    Controller1.Screen.setCursor(0, 1);
    //Controller1.Screen.print("%f", DrivetrainInertial.gyroRate(xaxis, dps));
    Controller1.Screen.print("%f", DrivetrainInertial.pitch(deg));
    wait(100, msec);
  }
}
