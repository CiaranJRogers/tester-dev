#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "inc/pins.h"

#define LED_PIN 25  // 

int main() 
{
    // stdio_init_all();
    // printf("Reading ADC on GPIO26\n");

    // // Initialize ADC
    // adc_init();
    // adc_gpio_init(26);       // ADC0 is on GPIO26
    // adc_select_input(0);     // Select ADC0

    // // adc_gpio_init(27);      
    // // adc_select_input(1);

    // // Initialize LED pin
    // gpio_init(LED_PIN);
    // gpio_set_dir(LED_PIN, GPIO_OUT);
    // gpio_put(LED_PIN, 1);    // Turn LED on initially

    // bool test_passed = false;

    // while (1) {
    //     const float conversion_factor = 3.3f / (1 << 12);
    //     uint16_t result = adc_read();
    //     float voltage = result * conversion_factor;
    //     float normalised_val = result / 4095.f; 

    //     if (!test_passed) {
    //         printf("Raw value: 0x%03x, voltage: %f V, normalised value:%.3f\n", result, voltage, normalised_val);
    //     }

    //    if (!test_passed && normalised_val >= 1.0f) {
    //         printf("Test Passed\n");
    //         test_passed = true;
    //    }

    //     sleep_ms(500);
    

static char event_str[128];

void gpio_event_string(char *buf, uint32_t events);

void gpio_callback(uint gpio, uint32_t events) {
    // Put the GPIO event(s) that just happened into event_str
    // so we can print it
    gpio_event_string(event_str, events);
    printf("GPIO %d %s\n", gpio, event_str);
}

int main() {
    stdio_init_all();

    printf("Hello GPIO IRQ\n");
    gpio_init(GPIO_WATCH_PIN);
    gpio_set_irq_enabled_with_callback(GPIO_WATCH_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    // Wait forever
    while (1);
}


static const char *gpio_irq_str[] = {
        "LEVEL_LOW",  // 0x1
        "LEVEL_HIGH", // 0x2
        "EDGE_FALL",  // 0x4
        "EDGE_RISE"   // 0x8
};

void gpio_event_string(char *buf, uint32_t events) {
    for (uint i = 0; i < 4; i++) {
        uint mask = (1 << i);
        if (events & mask) {
            // Copy this event string into the user string
            const char *event_str = gpio_irq_str[i];
            while (*event_str != '\0') {
                *buf++ = *event_str++;
            }
            events &= ~mask;

            // If more events add ", "
            if (events) {
                *buf++ = ',';
                *buf++ = ' ';
            }
        }
    }
    *buf++ = '\0';
}
    

while (1) {
        MSG msg; // message object to receive

        // generically WAIT for any message to arrive in the queue
        status = GetMessage(&msg, NULL, 0, 0);

        if (status == 0) { // message NOT to be processed?
            status = msg.wParam;
            break; // terminate the event loop
        }

        // dispatch to the appropriate "window proc"
        DispatchMessage(&msg);
    }

    return status; // return to Windows with the status of processing








    
}








    
}
