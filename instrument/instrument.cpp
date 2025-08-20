#include "instrument.hpp"
#include "instrument_data.hpp"

// This function acknowledges a state flip and updates the LED state accordingly
void Instrument::process(const InstrumentInputData& data, InstrumentOutputData& output)
{
    if (data.parameter.stateFlip)
    {
        // Reset the state flip after processing
        state = !state;
    }
    output.state.state = state;


}
