#include "hardware.hpp"
#include "hardware/gpio.h"
#include "pico/time.h"

Hardware::Hardware()
{
    buttonPin = 17;
    ledPin = 16;

    gpio_init(buttonPin);
    gpio_init(ledPin);

    gpio_set_dir(buttonPin, GPIO_IN);
    gpio_set_dir(ledPin, GPIO_OUT);

    gpio_pull_down(buttonPin); // Enable pull-down resistor on button pin
}

void Hardware::process_input(HardwareInputData& output) //input hardware definition
{

 output.buttonPress = gpio_get(buttonPin);
}

void Hardware::process_output(const HardwareOutputData& input)  //output hardware definition
{
    gpio_put(ledPin, input.ledState);
    // no sleep here
}
