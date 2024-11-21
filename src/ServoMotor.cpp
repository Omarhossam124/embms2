#include <Arduino.h>
#include "ServoMotor.h"


Servo myServo;

void servoInit(int pin) {
  myServo.attach(pin);
  myServo.write(0); // Close door initially
}

void openDoor() {
  myServo.write(90); // Open door
  delay(3000);
  myServo.write(0);  // Close door
}

void closeDoor() {
  myServo.write(0);
}
