#include "FrameworkArduino.h"

FrameworkArduino::FrameworkArduino(){
    Serial.begin(FrameworkArduino::velocidadSerial);
}

void FrameworkArduino::escribir(int pin, int valor){
    digitalWrite(pin, valor);
}

int FrameworkArduino::leer(int pin){
    return digitalRead(pin);
}

unsigned long FrameworkArduino::milisegundos() {
    return millis();
}

unsigned long FrameworkArduino::microsegundos(){
    return micros();
}

void FrameworkArduino::demorar(int milisegundos){
    delay(milisegundos);
}

void FrameworkArduino::pinSalida(int pin) {
    pinMode(pin, OUTPUT);
}
