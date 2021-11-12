//Tells the compiler to not include the header files multiple times
#pragma once

//Header files from FRC
#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include <rev/CANSparkMax.h>
#include <frc/smartdashboard/Field2d.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>
#include <fstream>


//Header files from us
#include "DriveSubsystem.h"
#include "test.h"


//Robot class inherits from TimedRobot
class Robot : public frc::TimedRobot {

  public:
      bool manualMode = false;

      void RobotInit() override;
      void RobotPeriodic() override;
      void DisabledInit() override;
      frc::Joystick primary{1};


      
      


  private:

    DriveSubsystem db{};
    test TEST{};
    bool enabled = false;
    bool previous = false;



};

//Notes:
//GetRawButton and GetRawButtonPressed are not the same
//button index starts at 1




