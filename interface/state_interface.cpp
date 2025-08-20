#include "state_interface.hpp"

// logic here to set hardware outputs based on the application's state

void StateInterface::process(const StateInputData& input, StateOutputData& output)  
{
    // Update the hardware output data based on the current state
    output.hardware.ledState = input.state.state; // Set LED state to the current state
}

