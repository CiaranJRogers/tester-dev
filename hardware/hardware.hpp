#ifndef HARDWARE_H
#define HARDWARE_H

#include "hardware_data.hpp"

class Hardware
{
	public:
		Hardware();
		~Hardware() = default;

		void process_input(HardwareInputData& output);
		void process_output(const HardwareOutputData& input);
		
	
	private:
		int buttonPin = 22;
		int ledPin = 21;
};

#endif // HARDWARE_H



