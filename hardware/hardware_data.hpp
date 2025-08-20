#ifndef HARDWARE_DATA_H
#define HARDWARE_DATA_H

struct HardwareInputData    // holds data read from the hardware (e.g. button states, sensor values etc.) 
{
    bool buttonPress = false;
};

struct HardwareOutputData   // holds data to be sent to the hardware ((HW/OP)) (e.g. LED states, actuator commands)
{
    bool ledState = false; 

};

#endif // HARDWARE_DATA_H