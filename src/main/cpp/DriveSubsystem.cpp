#include "Robot.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DriverStation.h>



void DriveSubsystem::Init(){

    dbLM.RestoreFactoryDefaults();
    dbRM.RestoreFactoryDefaults();

    dbLS.RestoreFactoryDefaults();
    dbRS.RestoreFactoryDefaults();
    //hello


    //we inverted the right side and set motors to follow each other
    dbLM.SetInverted(true);
    dbRM.SetInverted(false);

    dbLS.Follow(dbLM);
    dbRS.Follow(dbRM);

    dbRM.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    dbLM.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

    dbLM.SetSmartCurrentLimit(45);
    dbRM.SetSmartCurrentLimit(45);
    dbLS.SetSmartCurrentLimit(45);
    dbRS.SetSmartCurrentLimit(45);

    dbLM.Set(0);
    dbRM.Set(0);

    dbLM.BurnFlash();
    dbRM.BurnFlash();
    dbLS.BurnFlash();
    dbRS.BurnFlash();



}

void DriveSubsystem::Periodic(frc::Joystick &primary)
{

    //adds spice to drive base :)
    if(frc::DriverStation::GetInstance().GetJoystickName(0) == "FrSky Taranis Joystick"){
        lDrive = primary.GetRawAxis(0);
        rDrive = primary.GetRawAxis(2);
    }else{
        lDrive = primary.GetRawAxis(1);
        rDrive = primary.GetRawAxis(5);
    }
    
    frc::SmartDashboard::PutNumber("ldrive", lDrive);
    frc::SmartDashboard::PutNumber("rdrive", rDrive);
    frc::SmartDashboard::PutNumber("rdriveSpeed", dbRM.Get());
    //frc::SmartDashboard::PutNumber("encoder", dbRMEncoder.GetPosition());

    


    dbLM.Set(lDrive);
    dbRM.Set(rDrive);


}


void DriveSubsystem::Disabled(){
    dbRM.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    dbLM.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    dbLM.Set(0);
    dbRM.Set(0);
}



// auton functions:

