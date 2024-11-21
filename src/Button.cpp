#include "Button.h"
#include <Arduino.h>

int buttonPin;

void buttonInit(int pin) {
  buttonPin = pin;
  pinMode(buttonPin, INPUT_PULLUP);
}

bool isButtonPressed() {
  return digitalRead(buttonPin) == LOW;
}
