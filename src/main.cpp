#include <Arduino.h>
#include <WiFiNINA.h>
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include "Ultrasonic.h"
#include "PIR.h"
#include "Button.h"
#include "LED.h"
#include "Buzzer.h"
#include "ServoMotor.h"


const char ssid[] = "M";
const char pass[] = "11111111";

WiFiConnectionHandler wifiConnectionHandler(ssid, pass);

bool pirMotion = false;
bool buttonPressed = false;
bool doorOpen = false;

void setup() {
    Serial.begin(9600);
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    ArduinoCloud.begin(wifiConnectionHandler);

    // Cloud properties
    ArduinoCloud.addProperty(pirMotion, READ);
    ArduinoCloud.addProperty(buttonPressed, READWRITE);
    ArduinoCloud.addProperty(doorOpen, READWRITE);

    ultrasonicInit(2, 3);
    pirInit(4);
    buttonInit(5);
    ledInit(6);
    buzzerInit(7);
    servoInit(9);
}

void loop() {
    ArduinoCloud.update();

    pirMotion = detectMotion();
    if (pirMotion) {
        ledOn();
        buzzerOn();
        delay(500);
        ledOff();
        buzzerOff();
    }

    buttonPressed = isButtonPressed();
    if (buttonPressed) {
        openDoor();
    }
}
