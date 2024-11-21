#include "LED.h"
#include <Arduino.h>

int ledPin;

void ledInit(int pin) {
  ledPin = pin;
  pinMode(ledPin, OUTPUT);
}

void ledOn() {
  digitalWrite(ledPin, HIGH);
}

void ledOff() {
  digitalWrite(ledPin, LOW);
}
