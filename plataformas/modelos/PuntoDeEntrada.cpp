#include "PuntoDeEntrada.h"

PuntoDeEntrada::PuntoDeEntrada(const char *ruta) {
    this->ruta = ruta;
}

const char* PuntoDeEntrada::obtenerRuta() {
    return this->ruta;
}
