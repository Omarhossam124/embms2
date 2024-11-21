#include "Ultrasonic.h"
#include <Arduino.h>

int trig, echo;

void ultrasonicInit(int trigPin, int echoPin) {
  trig = trigPin;
  echo = echoPin;
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

long measureDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  return duration * 0.034 / 2; // Distance in cm
}
