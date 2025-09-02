#ifndef SYSTEM_ENGINE_HPP
#define SYSTEM_ENGINE_HPP

#include "instrument.hpp"
#include "instrument_data.hpp"
#include "parameter_interface.hpp"
#include "parameter_data.hpp"
#include "state_interface.hpp"
#include "state_data.hpp"
#include "hardware.hpp"
#include "hardware_data.hpp"
#include "tusb.h"


void cdc_task(void);


class Engine
{
	public:
		Engine();
		~Engine() = default;

		void run();
		void process();

		HardwareInputData hardware_input_data;
		ParameterData parameter_data;
		StateData state_data;
		HardwareOutputData hardware_output_data;

		Instrument instrument;
		ParameterInterface parameter_interface;
		StateInterface state_interface;
		Hardware hardware;
};



#endif // SYSTEM_ENGINE_HPP