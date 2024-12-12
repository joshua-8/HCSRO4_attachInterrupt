/**
   this code for reading distance from an HCSRO4 sensor uses attachInterrupt() to measure echos without long delays in the code

   example code for reading from an HC-SRO4 using an Alfredo Systems NoU3

   wiring an NoU3 to a HC-SRO4
   gnd --- gnd
   5v(servo power) --- Vcc
   PIN_SERVO_1 --- trig
   gnd --- R 1k --- PIN_SERVO_2 --- R 1k --- echo

   v1.0 initial version by joshua-8 2024-12-11
*/


#include <Arduino.h>
#include "HCSRO4.h"

const int PIN_SERVO_1 = 4;
const int PIN_SERVO_2 = 5;
const int PIN_SERVO_3 = 6;
const int PIN_SERVO_4 = 7;
const int PIN_SERVO_5 = 8;
const int PIN_SERVO_6 = 9;

//trig pin, echo pin, distanceMultiplier (1.0/148 for inch, 1.0/58 for cm),  (optional, default 20us) maxTimeToWaitForEcho (ms),  (optional) delayAfterReading(60ms recommended)
HCSRO4 distanceSensor1 = HCSRO4(PIN_SERVO_1, PIN_SERVO_2, 1.0 / 58);

void setup() {
  Serial.begin(115200);
  if (!distanceSensor1.begin()) {
    Serial.println("error setting up distance sensor (there's a limit of 8 sensors)");
  }
}

void loop() {
  // run returns true if there's a new distance or if the distance has been updated to 0 to indicate no echo received
  if (distanceSensor1.run()) {
    // getDistance() can be called whenever you want to get the most recent reading
    Serial.println(distanceSensor1.getDistance());
  }
}

