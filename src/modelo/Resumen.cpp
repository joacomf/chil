#include "Resumen.h"

void Resumen::registrarEscenarioConResultado(bool esExitoso) {
    this->cantidadEscenariosCompletados++;
}

int Resumen::escenarioCompletados() {
    return this->cantidadEscenariosCompletados;
}
