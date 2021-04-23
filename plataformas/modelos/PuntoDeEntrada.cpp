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
