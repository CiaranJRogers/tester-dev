#ifndef HARDWARE_H
#define HARDWARE_H

#include "hardware_data.hpp"

//EEPROM 
#define EEPROM_WRT_CTRL 11
#define EEPROM_SDA_PIN 12
#define EEPROM_SCL_PIN 13
//LEARN BTNS
#define BUTTON_A_PIN 0
#define BUTTON_B_PIN 1
#define BUTTON_C_PIN 2

//CV_ADCS
#define CV_A_ADC_PIN 27
#define CV_B_ADC_PIN 28
#define CV_C_ADC_PIN 29

//LEDS
#define LED_1 21
#define LED_2 22
#define LED_3 23
#define LED_4 24
#define LED_5 7
#define LED_6 10
//EEPROM
#define EEPROM_I2C_PORT i2c0
#define EEPROM_I2C_ADDR 0x50 // 7-bit address for M24M01 (A2/A1/A0 = 0)

class Hardware
{
	public:
		Hardware();
		~Hardware() = default;

		void process_input(HardwareInputData& output);
		void process_output(const HardwareOutputData& input);
		
	
	private:
		// int buttonPin = 17;
		// int ledPin = 16;
	
};

#endif // HARDWARE_H



