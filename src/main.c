

#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "log.h"

#define LED_PIN 25
#define ADC_PIN 26

int main()
{
stdio_init_all();

gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    

    log_open();
    LOG_INFO(
        "stuff\n"
            );

    
    while (1) {
    
        
    // gpio_put(LED_PIN, 1); // Turn LED on
    //     sleep_ms(1000); // Wait for 500 milliseconds
    //     gpio_put(LED_PIN, 0); // Turn LED off
    //     sleep_ms(500); // Wait for 500 milliseconds
    //     LOG_INFO("LED toggled\n");
        


    // adc_init(); // Initialize ADC
    // adc_gpio_init(ADC_PIN); // Initialize ADC pin
    // adc_select_input(0); // Select ADC input channel 0  
    // uint16_t adc_value = adc_read(); // Read ADC value
    // LOG_INFO("ADC Value: %d\n", adc_value); // Log ADC value
    // sleep_ms(100); // Wait for 1 second before next iteration

    // if (adc_value > 2000) { // Example condition to turn on LED
    //     gpio_put(LED_PIN, 1); // Turn LED on if ADC value is high
    //     LOG_INFO("LED ON due to high ADC value\n");
    // } else {
    //     gpio_put(LED_PIN, 0); // Turn LED off if ADC value is low
    //     LOG_INFO("LED OFF due to low ADC value\n");

        
    }
    return 0; 
}
