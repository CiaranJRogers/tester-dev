#ifndef PARAMETER_INTERFACE_H
#define PARAMETER_INTERFACE_H

#include "parameter_data.hpp"

class ParameterInterface
{


	public:
		ParameterInterface() = default;
		~ParameterInterface() = default;

		void process(const ParameterInputData& input, ParameterOutputData& output);

	private:
		bool lastButtonState = false;
};

#endif // PARAMETER_INTERFACE_H