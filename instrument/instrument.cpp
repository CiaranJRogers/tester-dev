#include "instrument.hpp"
#include "instrument_data.hpp"
#include <cstring>

// This function acknowledges a state flip and updates the LED state accordingly
void Instrument::process(const InstrumentInputData& data, InstrumentOutputData& output)
{
    if (data.parameter.stateFlip)
    {
        // Flip the state
        state = !state;
        
    }
    output.state.state = state ;  
}



