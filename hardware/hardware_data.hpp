#ifndef HARDWARE_DATA_H
#define HARDWARE_DATA_H

enum class SerialCommand {
    NONE,
    LED_ON,
    LED_OFF,
    LED_BLINK
    // whatever else you need
};



struct HardwareInputData    // holds data read from the hardware (e.g. button states, sensor values etc.) 
{
    bool buttonPress = false;
    SerialCommand command = SerialCommand::NONE;
   


    
};

struct HardwareOutputData   // holds data to be sent to the hardware ((HW/OP)) (e.g. LED states, actuator commands)
{
    bool ledState = false; 

};

#endif // HARDWARE_DATA_H