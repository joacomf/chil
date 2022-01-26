#include "EjecutorConManejoDeErrores.h"


EjecutorConManejoDeErrores::EjecutorConManejoDeErrores(Paso *paso, void (*funcion)()) : Ejecutor(paso),
                                                                                        funcion(funcion) {}

void EjecutorConManejoDeErrores::ejecutar() {
    try {
        this->funcion();
    } catch (exception& excepcion) {
        this->paso->esExitoso(false);
        this->paso->huboError(excepcion.what());
    }
}
