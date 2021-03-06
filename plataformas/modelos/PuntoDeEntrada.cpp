#include "PuntoDeEntrada.h"

PuntoDeEntrada::PuntoDeEntrada(const char *ruta) {
    this->ruta = ruta;
    this->metodo = GET;
}

PuntoDeEntrada::PuntoDeEntrada(const char *ruta, Metodo metodo) {
    this->ruta = ruta;
    this->metodo = metodo;
}

const char* PuntoDeEntrada::obtenerRuta() {
    return this->ruta;
}

Metodo PuntoDeEntrada::obtenerMetodo() {
    return this->metodo;
}

void PuntoDeEntrada::configurarRespuesta(const char *valor, const char *tipoDeContenido, int codigo) {
    this->respuesta = valor;
    this->tipo = tipoDeContenido;
    this->codigoDeRespuesta = codigo;
}

const char* PuntoDeEntrada::obtenerRespuesta() {
    return this->respuesta;
}

const char* PuntoDeEntrada::obtenerTipo() {
    return this->tipo;
}

int PuntoDeEntrada::obtenerCodigoDeRespuesta() const {
    return this->codigoDeRespuesta;
}
