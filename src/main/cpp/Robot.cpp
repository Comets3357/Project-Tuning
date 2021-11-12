#include "Robot.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/smartdashboard/Field2d.h>
#include <frc/DriverStation.h>
#include <string>
#include <iostream>




using namespace std;

void Robot::RobotInit() {

    db.Init();
    TEST.Init();
}


void Robot::RobotPeriodic(){
    db.Periodic(primary);
    TEST.Periodic(primary);
    frc::SmartDashboard::PutBoolean("Button", primary.GetRawButton(1));
}





void Robot::DisabledInit(){
    db.Disabled();
    //TEST.Disabled();

}




#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
