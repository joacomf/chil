#include "Resumen.h"

void Resumen::registrarEscenarioConResultado(bool esExitoso) {
    this->cantidadEscenariosCompletados++;

    if (esExitoso) {
        this->cantidadEscenariosExitosos++;
    }else {
        this->cantidadEscenariosFallidos++;
    }
}

int Resumen::escenarioCompletados() const {
    return this->cantidadEscenariosCompletados;
}

int Resumen::escenarioFallidos() const {
    return this->cantidadEscenariosFallidos;
}

int Resumen::escenariosExitosos() const {
    return this->cantidadEscenariosExitosos;
}
