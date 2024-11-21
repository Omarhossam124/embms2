#include "PIR.h"
#include <Arduino.h>

int pirPin;

void pirInit(int pin) {
  pirPin = pin;
  pinMode(pirPin, INPUT);
}

bool detectMotion() {
  return digitalRead(pirPin) == HIGH;
}
