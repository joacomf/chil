#include "Resumen.h"

void Resumen::registrarEscenarioConResultado(bool esExitoso) {
    this->cantidadEscenariosCompletados++;

    if (esExitoso) {
        this->cantidadEscenariosExitosos++;
    }else {
        this->cantidadEscenariosFallidos++;
    }
}

int Resumen::escenarioCompletados() {
    return this->cantidadEscenariosCompletados;
}

int Resumen::escenarioFallidos() {
    return this->cantidadEscenariosFallidos;
}
