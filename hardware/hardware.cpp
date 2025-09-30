#include "hardware.hpp"
#include "hardware/gpio.h"
#include "pico/time.h"

static Hardware* g_hardware_instance = nullptr;

bool Hardware::blink_callback(repeating_timer_t* t) {
    if (g_hardware_instance != nullptr) {
        g_hardware_instance->blinkState = !g_hardware_instance->blinkState;
        gpio_put(g_hardware_instance->led, g_hardware_instance->blinkState);
    }
    return true;
}       



Hardware::Hardware()
{

    gpio_init(button);
    gpio_pull_down(button); // Enable pull-down resistor on button pin
    gpio_set_dir(button, GPIO_IN);


    gpio_init(led);
    blinkMode = false;
    blinkState = false;
    gpio_set_dir(led, GPIO_OUT);

    g_hardware_instance = this;
}





void Hardware::process_input(HardwareInputData& output)
{
    output.buttonPress = gpio_get(button);
    
    switch(output.command) {
        case SerialCommand::LED_ON:
            // cancel blink mode if already active
            if (blinkMode) {
                cancel_repeating_timer(&blink_timer);
                blinkMode = false;
            }
            // force LED on
            gpio_put(led, true);
            break;
            
        case SerialCommand::LED_OFF:
            // cancel blink mode if already active
            if (blinkMode) {
                cancel_repeating_timer(&blink_timer);
                blinkMode = false;
            }
            // force LED off
            gpio_put(led, false);
            break;
            
        case SerialCommand::LED_BLINK:
            // start blink mode if not already active
            if (!blinkMode) {
                blinkMode = true;
                add_repeating_timer_ms(500, blink_callback, nullptr, &blink_timer);
            }
            break;
            
        default:
            // No command so do nothing
            break;
    }
    
    // reset command after processing
    output.command = SerialCommand::NONE;
}







void Hardware::process_output(const HardwareOutputData& input)
{
    // only update LED if not in blink mode
    if (!blinkMode) {
        gpio_put(led, input.ledState);
    }

   
}