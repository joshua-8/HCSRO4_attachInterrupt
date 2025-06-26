# HCSRO4_attachInterrupt

Use interrupts to read HC-SRO4 distance sensors without delays or blocking the main loop.

[![arduino-library-badge](https://www.ardu-badge.com/badge/HCSRO4_attachInterrupt.svg?)](https://www.ardu-badge.com/HCSRO4_attachInterrupt)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/joshua1024/library/HCSRO4_attachInterrupt.svg)](https://registry.platformio.org/libraries/joshua1024/HCSRO4_attachInterrupt)




Tested on the [Alfredo Systems NoU3](http://www.alfredosys.com/products/alfredo-nou3/)

wiring:

![nou3 wiring photo](https://github.com/user-attachments/assets/f9214af8-d9cd-45d6-90b1-0718b5362c1e)

The HC-SRO4 needs to be powered by 5 volts not 3.3v (so use the regulated 5 volt servo power).

The ESP32-S3 in the NoU3 can only provide 3.3 volt outputs and can only survive 3.3 volt inputs.

A 3.3 volt signal is enough to trigger the HC-SRO4, but the HC-SRO4 will output a 5 volt echo signal which would be bad for the NoU3 if connected directly.

Two resistors can be used to divide the echo signal to a safe voltage for the NoU3.   echo -- resistor -- NoU3 pin -- resistor -- ground

The resistors should be approximately equal and can be most values (1k -100k ish). I used two 1k resistors.
