#include <Arduino.h>

#define LED 2
#define BUTTON 4

void setup() {
    Serial.begin(115200);

    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT);
}

void loop() {
    if (digitalRead(BUTTON) == HIGH) {
        digitalWrite(LED, HIGH);
    } else {
        digitalWrite(LED, LOW);
    }

    delay(20);
}