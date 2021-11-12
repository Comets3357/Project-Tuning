//Tells the compiler to not include the header files multiple times
#pragma once

//Header files from FRC
#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include <rev/CANSparkMax.h>
#include <frc/smartdashboard/Field2d.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>

#include <iostream>
#include <fstream>

class test {
    
    public: 
        void Init();
        void Periodic(frc::Joystick &primary);
        std::string values(frc::Joystick &primary);
        


    private:
        std::ofstream log_File;
        bool pressed = false;
        bool pressed1 = false;
        bool done  =true;
        int x = 0;

        //use this to read data to code from shuffleboard. 
        nt::NetworkTableEntry run = frc::Shuffleboard::GetTab("test")
                     .Add("run files", 1)
                     .GetEntry();
                        
        

}; 