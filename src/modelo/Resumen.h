#ifndef CHIL_RESUMEN_H
#define CHIL_RESUMEN_H

#include <string>
#include <modelo/Escenario.h>
#include "utils/literales.h"

using literales::aTexto;

class Resumen {

public:
    void registrarEscenarioConResultado(bool esExitoso);

    int escenarioCompletados() const;
    int escenarioFallidos() const;

    int escenariosExitosos() const;

    string imprimible() const;

private:
    constexpr static const char *const INDICADOR_COMPLETADOS = "Completados: ";
    constexpr static const char *const INDICADOR_EXITOSOS = "Exitosos: ";
    constexpr static const char *const INDICADOR_FALLIDOS = "Fallidos: ";
    constexpr static const char *const SEPARADOR_RESULTADOS = ", ";

    int cantidadEscenariosCompletados = 0;
    int cantidadEscenariosFallidos = 0;
    int cantidadEscenariosExitosos = 0;
};


#endif //CHIL_RESUMEN_H
