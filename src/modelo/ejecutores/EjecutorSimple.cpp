#include "EjecutorSimple.h"

EjecutorSimple::EjecutorSimple(Paso *paso, bool (*funcion)()) : Ejecutor(paso), funcion(funcion) {}

void EjecutorSimple::ejecutar() {
    bool ejecucion = this->funcion();
    this->paso->esExitoso(ejecucion);
}

