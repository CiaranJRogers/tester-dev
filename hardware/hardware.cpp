#include "hardware.hpp"
#include "hardware/gpio.h"
#include "pico/time.h"

Hardware::Hardware()
{
    buttonPin = 22;
    ledPin = 21;

    gpio_init(buttonPin);
    gpio_init(ledPin);
    
}

void Hardware::process_input(HardwareInputData& output) //input hardware definition
{
   gpio_get(buttonPin);
}  

void Hardware::process_output(const HardwareOutputData& input)  //output hardware definition
{
    gpio_put(ledPin, input.ledState);
}
