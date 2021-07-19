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

string Resumen::imprimible() const {
    string impresion = string();

    impresion.append(INDICADOR_COMPLETADOS + literal(this->cantidadEscenariosCompletados) + SEPARADOR_RESULTADOS);
    impresion.append(INDICADOR_EXITOSOS + literal(this->cantidadEscenariosExitosos) + SEPARADOR_RESULTADOS);
    impresion.append(INDICADOR_FALLIDOS + literal(this->cantidadEscenariosFallidos) );

    return impresion;
}
