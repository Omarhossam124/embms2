#include "Buzzer.h"
#include <Arduino.h>

int buzzerPin;

void buzzerInit(int pin) {
  buzzerPin = pin;
  pinMode(buzzerPin, OUTPUT);
}

void buzzerOn() {
  gpio_set_dir(buzzerPin , 1) ;  
  gpio_put(buzzerPin , 1) ; 

 }

void buzzerOff() {
  digitalWrite(buzzerPin, LOW);
}
