

#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "log.h"

#define LED_PIN 25
#define ADC_PIN 26

int main()
{
stdio_init_all();
    adc_init();
    adc_gpio_init(ADC_PIN); 
    adc_select_input(0); // GPIO 26 is ADC input 0 

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    

    log_open();
    LOG_INFO(
        "Trying to get the fucking LED to blink for fucks sake please \n"
            );

    


    while (1) {
        /* uint16_t raw = adc_read(); 
        LOG_INFO("Fader ADC value: %u\n", raw);
        sleep_ms(100); // Read every 100ms

        sleep_ms(100);
    
        sleep_ms(100); */
        gpio_put(LED_PIN, 1); // LED on
        sleep_ms(250);
        gpio_put(LED_PIN, 0); // LED off
        sleep_ms(250);
    }
    return 0; 
}
