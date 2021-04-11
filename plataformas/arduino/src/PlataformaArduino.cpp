#include "PlataformaArduino.h"

PlataformaArduino::PlataformaArduino(){
    Serial.begin(PlataformaArduino::velocidadSerial);
}

void PlataformaArduino::escribir(int pin, int valor){
    digitalWrite(pin, valor);
}

int PlataformaArduino::leer(int pin){
    return digitalRead(pin);
}

unsigned long PlataformaArduino::milisegundos() {
    return millis();
}

unsigned long PlataformaArduino::microsegundos(){
    return micros();
}

void PlataformaArduino::demorar(int milisegundos){
    delay(milisegundos);
}

void PlataformaArduino::pinSalida(int pin) {
    pinMode(pin, OUTPUT);
}

void PlataformaArduino::consola(const char *texto) {
    Serial.println(texto);
}

bool PlataformaArduino::crearRedWiFi(const char *nombre, const char *clave) {
  return true;
}