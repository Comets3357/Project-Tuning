#pragma once

#include <frc/TimedRobot.h>
#include <rev/CANSparkMax.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/simulation/SimDeviceSim.h>
#include <frc/Encoder.h>
#include <frc/simulation/EncoderSim.h>
#include <frc/smartdashboard/Field2d.h>

#include <frc/AnalogGyro.h>
#include <frc/simulation/AnalogGyroSim.h>





class DriveSubsystem {
    
    public: 
        void Init();
        void Periodic(frc::Joystick &primary);
        void Disabled();


    private:

        double lDrive = 0;
        double rDrive = 0;

        


//motors:

        static const int leftLeadDeviceID = 1, leftFollowDeviceID = 2, rightLeadDeviceID = 3, rightFollowDeviceID = 4;
        rev::CANSparkMax dbLM{leftLeadDeviceID, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax dbRM{rightLeadDeviceID, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax dbLS{leftFollowDeviceID, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax dbRS{rightFollowDeviceID, rev::CANSparkMax::MotorType::kBrushless};

        //rev::CANEncoder dbRMEncoder = dbRM.GetEncoder();
        //rev::CANEncoder dbLMEncoder = dbLM.GetEncoder();
        //frc::sim::SimDeviceSim rencoderSim{rev::CANEncoder dbRMEncoder, dbRM.GetEncoder()};
        frc::Encoder m_leftEncoder{0, 1};
        frc::Encoder m_rightEncoder{2, 3};
        frc::sim::EncoderSim m_leftEncoderSim{m_leftEncoder};
        frc::sim::EncoderSim m_rightEncoderSim{m_rightEncoder};


// Create our gyro objectl ike we would on a real robot.
        frc::AnalogGyro m_gyro{1};

// Create the simulated gyro object, used for setting the gyro
// angle. Like EncoderSim, this does not need to be commented out
// when deploying code to the roboRIO.
        frc::sim::AnalogGyroSim m_gyroSim{m_gyro};



        /* rev::CANPIDController dbRM_pidController = dbRM.GetPIDController();
        rev::CANPIDController dbLM_pidController = dbLM.GetPIDController(); */
    
        

//gyro:


}; 
