#ifndef HARDWARE_H
#define HARDWARE_H

#include "hardware_data.hpp"
#include "pico/time.h"
#include "hardware/timer.h"





class Hardware
{
	public:
		Hardware();
		~Hardware() = default;

		void process_input(HardwareInputData& output);
		void process_output(const HardwareOutputData& input);
		
	
	private:
		int button = 17;
        int led = 16;
		int adc = 26; 
        bool blinkMode = false;
        bool blinkState = false;
        repeating_timer_t blink_timer;

		
        static bool blink_callback(repeating_timer_t* t);

	
};

#endif // HARDWARE_H



