#ifndef PARAMETER_DATA_H
#define PARAMETER_DATA_H

#include "hardware_data.hpp"

struct ParameterData
{
	bool stateFlip = false;
	
};

struct ParameterInputData
{
	const HardwareInputData& hardware;
};

struct ParameterOutputData
{
	ParameterData& parameter;
};

#endif // PARAMETER_DATA_H