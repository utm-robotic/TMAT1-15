#include "Devices.h"

void avanzar(int dir, double dis, int vel){
  Drivetrain.setDriveVelocity(vel, pct);
  if(dir == 1){
    Drivetrain.driveFor(forward, dis, inches);
  }
  else if(dir == 2){
    Drivetrain.driveFor(reverse, dis, inches);
  }
}

void giroR(double grad, int vel){
  Drivetrain.setTurnVelocity(vel, pct);
  Drivetrain.turnToRotation(grad, deg);
}

void recolectar(int rep){
    Lanzador.setVelocity(100,pct);
    Lanzador.spin(forward);
    Recolector.setPosition(0, deg);
    Recolector.setVelocity(100,pct);
    wait(1.2,sec);
    repeat(rep){
        Recolector.spinToPosition(-390, deg);
        wait(2, msec);
        Recolector.spin(fwd);
        waitUntil(Bumper1.value() == true);
        Recolector.stop(brake);
        Recolector.setPosition(0, deg);
        wait(0.25,sec);
        //waitUntil(Lanzador.velocity(volt) >= 11.5);
  }
}

void cruzar(){
  bool salir1 = true;
  bool salir2 = true;
  Recolector.setVelocity(100,pct);
  Drivetrain.setDriveVelocity(60,pct);
  while(salir1 == true){
    Drivetrain.drive(reverse);
    if(DrivetrainInertial.pitch(deg) >= -22){//22
      
      while(salir2 == true){
        if(DrivetrainInertial.pitch(deg) >= -22){
          Drivetrain.drive(reverse);
        }
        else if(DrivetrainInertial.pitch(deg) <= -5 && DrivetrainInertial.pitch(deg) >=-21){//5 21
          //Recolector.spin(reverse);
          wait(0.5, sec);
          Recolector.stop(hold);
        }
        else if (DrivetrainInertial.pitch(deg) <= -4){
          Drivetrain.drive(reverse);
          wait(0.5,sec);
          waitUntil(DrivetrainInertial.pitch(deg) <=2);
          Drivetrain.stop(hold);
          salir1 = false;
          salir2 = false;
        }
      }

    }
    else{
      Drivetrain.setDriveVelocity(50,pct);
      Drivetrain.drive(reverse);
    }
  }
}
  /*Recolector.setVelocity(100,pct);
  Drivetrain.setDriveVelocity(50,pct);
  Drivetrain.drive(forward);
  waitUntil(DrivetrainInertial.pitch(deg) >= 22);
  Drivetrain.stop();
  Recolector.spin(reverse);
  waitUntil(DrivetrainInertial.pitch(deg) <= 5);
  Recolector.stop();
  Drivetrain.drive(forward);
  wait(1,sec);
  Drivetrain.stop();*/
