#ifndef STATE_INTERFACE_H
#define STATE_INTERFACE_H

#include "state_data.hpp"

class StateInterface
{
	public:
		StateInterface() = default;
		~StateInterface() = default;

		void process(const StateInputData& input, StateOutputData& output);

	private:
};

#endif // STATE_INTERFACE_H