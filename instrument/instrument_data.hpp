#ifndef INSTRUMENT_DATA_H
#define INSTRUMENT_DATA_H

//useful for if any audio is passed through

#include "parameter_data.hpp"
#include "state_data.hpp"

struct InstrumentInputData
{
	const ParameterData& parameter;
};

struct InstrumentOutputData
{
	StateData& state;
};

#endif // INSTRUMENT_DATA_H