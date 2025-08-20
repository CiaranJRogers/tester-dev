#include "parameter_interface.hpp"
#include <cstdio>


void ParameterInterface::process(const ParameterInputData& input, ParameterOutputData& output)
{
    // Check if the button state has changed
    if (input.hardware.buttonPress != lastButtonState)
    {
        output.parameter.stateFlip = true; // Indicate a state flip
    }
    
    // Store the last button state
    lastButtonState = input.hardware.buttonPress;
}
