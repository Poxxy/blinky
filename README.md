# blinky
Blinky program for Pi Pico

Program blinks on board LED then off board LED. The board setup should be as follows:
- Wire from GPIO 19 to LED. 
- Wire from LED to Resistor
- Wire from Resistor to - rail
- Wire from - rail to ground pin.

Make sure the LED is oriented the correct way. If the LED isn't lighting up, the long and short ends may need to be swapped. 

Also make sure you use GPIO 19, not physical pin 19 (which is GPIO14)

# Building

Make sure to have pico-sdk in a parellel directory to the blinky directory containing this repo.

- mkdir build
- cd build
- cmake ..
- make

Then copy the blinky.uf2 file over to the RP2040 while in flash mode (which can be set by holding BOOTSEL during connection with microusb)

Done!
