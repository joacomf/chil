#ifndef CHIL_FRAMEWORKARDUINO_H
#define CHIL_FRAMEWORKARDUINO_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ESPAsyncWebServer.h>

#include <Plataforma.h>
#include "../../modelos/PuntoDeEntrada.h"


class PlataformaArduino: public Plataforma {
private:
    int velocidadSerial = 115200;
    bool apEncendido = false;
    bool servidorCorriendo = false;

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

    void configurarPuntoDeEntrada(PuntoDeEntrada *puntoDeEntrada);

    bool estaServidorCorriendo();
};


#endif //CHIL_FRAMEWORKARDUINO_H
