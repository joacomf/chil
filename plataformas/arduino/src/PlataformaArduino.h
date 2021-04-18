#ifndef CHIL_FRAMEWORKARDUINO_H
#define CHIL_FRAMEWORKARDUINO_H

#include <Arduino.h>
#include <Plataforma.h>
#include <WiFi.h>

#include <HTTPClient.h>
#include <ESPAsyncWebServer.h>

class PlataformaArduino: public Plataforma {
private:
    int velocidadSerial = 115200;
    bool apEncendido = false;
    AsyncWebServer* servidor;

public:
    PlataformaArduino();
    void consola(const char* text);
    void escribir(int pin, int valor);
    int leer(int pin);
    void demorar(int milisegundos);
    unsigned long milisegundos();
    unsigned long microsegundos();
    void pinSalida(int pin);
    bool crearRedWiFi(const char *nombre, const char *clave);
    bool estaAPEncendido();
    bool apagarWiFi();
    void crearServidorWeb();
};


#endif //CHIL_FRAMEWORKARDUINO_H
