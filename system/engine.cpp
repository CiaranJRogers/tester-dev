#include "engine.hpp"

#include <pico/stdlib.h>
#include <chrono>
#include <pico/time.h>

static constexpr std::chrono::microseconds ENGINE_FRAME_PERIOD {1 * 1000};

static volatile bool run_engine;
bool engine_callback(repeating_timer_t* t)
{
    (void)t;
    run_engine = true;
    return true;
}

Engine::Engine()
{

}

void Engine::run()
{
	run_engine = true;

	// Set up timer if requested
	repeating_timer_t eng_timer;
	if constexpr (ENGINE_FRAME_PERIOD.count() != 0)
	{
		add_repeating_timer_us(-ENGINE_FRAME_PERIOD.count(), engine_callback, NULL, &eng_timer);
	}

	while (1)
	{
		if (run_engine)
		{
			this->process();

			if constexpr (ENGINE_FRAME_PERIOD.count() != 0)
			{
				run_engine = false;
			}
		}
	}
}

void Engine::process()
{
	hardware.process_input(hardware_input_data); //read hardware inputs (e.g. button state)

	{
		const ParameterInputData input	
		{
			.hardware = hardware_input_data	// pass hardware inputs to parameter layer
		};

		ParameterOutputData output
		{
			.parameter = parameter_data	// prepare parameter output for processing
		};

		parameter_interface.process(input, output);	// process parameters (interpret button press)
	}

	{
		const InstrumentInputData input
		{
			.parameter = parameter_data	// pass parameters to instrument layer
		};

		InstrumentOutputData output
		{
			.state = state_data //prepare instrument output
		};

		instrument.process(input, output);	//process instrument logic (e.g. decide LED state)
	}

	{
		const StateInputData input
		{
			.state = state_data // pass instrument state to state layer
		};

		StateOutputData output
		{
			.hardware = hardware_output_data	// prepare state output
		};

		state_interface.process(input, output);	//	process state output
	}

	hardware.process_output(hardware_output_data);	// write outputs to hardware (e.g. set LED)
}
