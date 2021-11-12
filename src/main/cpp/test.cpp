

#include "Robot.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DriverStation.h>
#include <frc/Preferences.h>



void test::Init(){
    //create file
    std::string filePath;

    filePath = "/home/lvuser/hello.txt";

    log_File.open(filePath); 
    log_File << "hello" << "\n";  //checks to see if its opened
    //for some reason this won't run ^^^ unless there's something in periodic also running along side it
    //the code in periodic more or less has to log in order for this to log i think
}

void test::Periodic(frc::Joystick &primary)
{
    //this is getting values from the smart dashboard and you read in values from dashboard into this code
    // int v = frc::SmartDashboard::GetNumber("write1",1);
    // frc::SmartDashboard::PutNumber("Write2", v);
    // if(v == 4){
    //     log_File << "mello" << "\n";
    // }else{
    //     log_File << "yello" << "\n";
    // }


    //READING FROM THE DASHBOARD BUT THROUGH SHUFFLEBOARD
    // frc::SmartDashboard::PutNumber("values", run.GetDouble(0));
    // if(run.GetDouble(0) == 4){
    //     log_File << "hello" << "\n";
    // }

    //this doesn't work. The minute I put code in a loop of sorts, nothing prints, not even the init function
    if(true){
        log_File << "helo" << "\n";
        //x++;
    }
    
    //if this code below is uncommented with the code above also uncommented, yelo will continuously print but the helo won't, the init print will also print
    //log_File << "yelo" << "\n";


    //THE FOLLOWING CODE SEGMENTS ARE SUPPOSED TO GET THE CODE TO ONLY RUN ONCE, RATHER THAN CONTINOUSLY SINCE IT IS IN PERIODIC
    //tried to use the joysticks to print values but doesn't work, this is relativley complicated, not needed
    //should work like a toggle
    //log_File << "hello" << "\n";
    // if(primary.GetRawButtonPressed(1)){
    //     pressed = !pressed;
    // }
    // if(!pressed){
    //     log_File << "test" << "\n";
    // }

    //-------------------------------------------------------------

    //if true, print, then set to false, should be simple code
    // if(primary.GetRawButtonPressed(1)){
    //     pressed1 = true;
    // }

    // if(pressed1){
    //     log_File << "Hello" << "\n";
    //     pressed1 = false;
    // }
    //x++;

    //-------------------------------------------------------------
    
    // pressed = primary.GetRawButtonPressed(1);
    // if(pressed){
    //     log_File << "Hello" << "\n";
    // }
        
    
    //-------------------------------------------------------------

    //there used to be a disabled function where the file is closed (.closed()), but I realized that the robot is disabled before it's even initialized 
    //meaning that the file is closed even before it's written to and thus nothing can be writen to the code, so don't close the file. 

}
