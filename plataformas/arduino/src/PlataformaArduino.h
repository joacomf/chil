#ifndef CHIL_FRAMEWORKARDUINO_H
#define CHIL_FRAMEWORKARDUINO_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ESPAsyncWebServer.h>
#include <DNSServer.h>

#include <Plataforma.h>
#include "../../modelos/PuntoDeEntrada.h"


class PlataformaArduino: public Plataforma {
private:
    int velocidadSerial = 115200;
    bool apEncendido = false;
    bool servidorCorriendo = false;

    AsyncWebServer* servidor;

    IPAddress ipLocal = IPAddress(192, 168, 4, 1);
    IPAddress sinIPDeclarada = INADDR_NONE;
    IPAddress dns = IPAddress(192, 168, 4, 254);

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
    void configurarPuntoDeEntrada(PuntoDeEntrada* puntoDeEntrada);
    bool estaServidorCorriendo() const;
    void eliminarServidorWeb();

    static void configurarMockUrls();

    [[noreturn]] static void configurarServidorDNS(void *parametros);

    static const byte DNS_PORT = 53;

    static void eliminarMocksUrls();

    static const IPAddress &dnsIP();
};

TaskHandle_t manejadorTareaDeConfiguracionServidorDNS = nullptr;

#endif //CHIL_FRAMEWORKARDUINO_H
