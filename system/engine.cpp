#include "engine.hpp"

#include <pico/stdlib.h>
#include <chrono>
#include <pico/time.h>
#include "tusb.h"

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
		tud_task();
      	cdc_task();
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

void cdc_task(void) {
  // connected() check for DTR bit
  // Most but not all terminal client set this when making connection
  // if ( tud_cdc_connected() )
  {
    // connected and there are data available
    if (tud_cdc_available()) {
      // read data
      char buf[64];
      uint32_t count = tud_cdc_read(buf, sizeof(buf));
      (void) count;

      // Echo back
      // Note: Skip echo by commenting out write() and write_flush()
      // for throughput test e.g
      //    $ dd if=/dev/zero of=/dev/ttyACM0 count=10000
      tud_cdc_write(buf, count);
      tud_cdc_write_flush();
    }
  }
}

// Invoked when cdc when line state changed e.g connected/disconnected
void tud_cdc_line_state_cb(uint8_t itf, bool dtr, bool rts) {
  (void) itf;
  (void) rts;

  // TODO set some indicator
  if (dtr) {
    // Terminal connected
  } else {
    // Terminal disconnected
  }
}

// Invoked when CDC interface received data from host
void tud_cdc_rx_cb(uint8_t itf) {
  (void) itf;
}

void tud_resume_cb(void){
} // Invoked when usb bus is resumed
