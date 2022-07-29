#include "pico/stdlib.h"

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    // On board LED pin
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Breadboard LED Pin using PIN 19 to power it.
    const uint PIN_19 = 19;
    gpio_init(PIN_19);
    gpio_set_dir(PIN_19, GPIO_OUT);
    
    while (true) {
        // On board LED pin
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);

        // Breadboard LED Pin using PIN 19 to power it.
        gpio_put(PIN_19, 1);
        sleep_ms(250);
        gpio_put(PIN_19, 0);
        sleep_ms(250);
    }
#endif
}