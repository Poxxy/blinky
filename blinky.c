#include "pico/stdlib.h"

void simpleSieve(bool mark[], int limit)
{
    // Create a boolean array "mark[0..limit-1]" and
    // initialize all entries of it as true. A value
    // in mark[p] will finally be false if 'p' is Not
    // a prime, else true.
    
    for(int i = 0; i<limit; i++) {
      mark[i] = true;
    }
  
    // One by one traverse all numbers so that their
    // multiples can be marked as composite.
    for (int p=2; p*p<limit; p++)
    {
        // If p is not changed, then it is a prime
        if (mark[p] == true)
        {
            // Update all multiples of p
            for (int i=p*p; i<limit; i+=p)
                mark[i] = false;
        }
    }
}


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

    // Signal program is starting.
    for (int i = 0; i < 3; i++) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }
    
    int limit = 10;
    bool mark[limit];

    simpleSieve(mark, limit);

    for (int p=2; p<limit; p++) {
        if (mark[p] == true) {
            for (int blinks = 0; blinks < p; blinks++) {
                gpio_put(PIN_19, 1);
                sleep_ms(250);
                gpio_put(PIN_19, 0);
                sleep_ms(250);
            }
            sleep_ms(1000);
            gpio_put(PIN_19, 1);
            sleep_ms(1000);
            gpio_put(PIN_19, 0);
            sleep_ms(250);
        }
        
    }

#endif
}
