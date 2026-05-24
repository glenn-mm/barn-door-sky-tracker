#include "AccelStepper.h"

// Motor pin definitions:
#define motorPin1  8      // IN1 on the ULN2003 driver
#define motorPin2  9      // IN2 on the ULN2003 driver
#define motorPin3  10     // IN3 on the ULN2003 driver
#define motorPin4  11     // IN4 on the ULN2003 driver

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper library with 28BYJ-48 stepper motor:
AccelStepper stepper = AccelStepper(AccelStepper::FULL4WIRE, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  // Set the maximum steps per second:
  stepper.setMaxSpeed(67);
    // Set the current position to 0:A
  stepper.setCurrentPosition(0);
  // Run the motor forward at 66 steps/second
  stepper.setSpeed(66);
}

void loop() {
  stepper.runSpeed();
}