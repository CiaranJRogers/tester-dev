#include "state_interface.hpp"

// logic here to set hardware outputs based on the application's state

void StateInterface::process(const StateInputData& input, StateOutputData& output)  
{
    output.hardware.ledState = input.state.state;
}

