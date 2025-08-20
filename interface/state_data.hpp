#ifndef STATE_DATA_H
#define STATE_DATA_H

#include "hardware_data.hpp"

struct StateData
{

	bool state = false;
};

struct StateInputData
{
	const StateData& state;
};

struct StateOutputData
{
	HardwareOutputData& hardware;
};

#endif // STATE_DATA_H