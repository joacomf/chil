#include "PlataformaArduino.h"

PlataformaArduino::PlataformaArduino() {
    Serial.begin(PlataformaArduino::velocidadSerial);
}

void PlataformaArduino::escribir(int pin, int valor) {
    digitalWrite(pin, valor);
}

int PlataformaArduino::leer(int pin) {
    return digitalRead(pin);
}

unsigned long PlataformaArduino::milisegundos() {
    return millis();
}

unsigned long PlataformaArduino::microsegundos() {
    return micros();
}

void PlataformaArduino::demorar(int milisegundos) {
    delay(milisegundos);
}

void PlataformaArduino::pinSalida(int pin) {
    pinMode(pin, OUTPUT);
}

void PlataformaArduino::consola(const char *texto) {
    Serial.println(texto);
}

bool PlataformaArduino::crearRedWiFi(const char *nombre, const char *clave) {
    WiFi.enableAP(true);
    this->apEncendido = WiFi.softAP(nombre, clave);
    return this->apEncendido;
}

bool PlataformaArduino::estaAPEncendido() {
    return this->apEncendido;
}

bool PlataformaArduino::apagarWiFi() {
    this->apEncendido = WiFi.softAPdisconnect();
    return this->apEncendido;
}

void PlataformaArduino::eliminarServidorWeb() {
    if (this->servidorCorriendo) {
        this->servidor->end();
        this->servidorCorriendo = false;
    }
}

void PlataformaArduino::crearServidorWeb() {
    if (!this->servidorCorriendo) {
        this->servidor = new AsyncWebServer(80);
        this->servidor->on("/chil-ping", HTTP_GET, [](AsyncWebServerRequest *request) {
            request->send(200, "text/plain", "chil-pong");
        });

        this->servidor->begin();
        this->servidorCorriendo = true;
    }
}

bool PlataformaArduino::estaServidorCorriendo() const {
    return this->servidorCorriendo;
}

void PlataformaArduino::configurarPuntoDeEntrada(PuntoDeEntrada* puntoDeEntrada) {
    WebRequestMethod metodoAConfigurar = HTTP_GET;

    if (puntoDeEntrada->obtenerMetodo() == POST) {
        metodoAConfigurar = HTTP_POST;
    }

    this->servidor->on(puntoDeEntrada->obtenerRuta(), metodoAConfigurar, [puntoDeEntrada](AsyncWebServerRequest *request) {
        request->send(200, puntoDeEntrada->obtenerTipo(), puntoDeEntrada->obtenerRespuesta());
    });

    this->demorar(100);
}