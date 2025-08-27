#include "parameter_interface.hpp"
#include <cstdio>


void ParameterInterface::process(const ParameterInputData& input, ParameterOutputData& output)
{
    // Check if  button state has changed
    if (input.hardware.buttonPress != lastButtonState)
    {
        output.parameter.stateFlip = (input.hardware.buttonPress);
    }
    else
    {
        output.parameter.stateFlip = false;
    }

    // Store the last button state
    lastButtonState = input.hardware.buttonPress;
}
