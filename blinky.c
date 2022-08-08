#include "pico/stdlib.h"

void startup() {
    // On board LED pin
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Signal program is starting.
    for (int i = 0; i < 3; i++) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }
}

void pin19_blink() {
    // Breadboard LED Pin using PIN 19 to power it.
    const uint PIN_19 = 19;
    gpio_init(PIN_19);
    gpio_set_dir(PIN_19, GPIO_OUT);

    gpio_put(PIN_19, 1);
    sleep_ms(250);
    gpio_put(PIN_19, 0);
    sleep_ms(250);
}

void read_button() {
    const uint PIN_14 = 14;
    gpio_init(PIN_14);
    gpio_set_dir(PIN_14, GPIO_IN);


    while (1) {
        int state = gpio_get(PIN_14);

        if (state == 1) {
            pin19_blink();
        }
    }

    
}

int main() {

    startup();

    read_button();

}
