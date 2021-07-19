#ifndef CHIL_RESUMEN_H
#define CHIL_RESUMEN_H

static const char *const INDICADOR_COMPLETADOS = "Completados: ";

static const char *const INDICADOR_EXITOSOS = "Exitosos: ";

static const char *const INDICADOR_FALLIDOS = "Fallidos: ";

static const char *const SEPARADOR_RESULTADOS = ", ";

#include <string>
#include <modelo/Escenario.h>

class Resumen {

public:
    void registrarEscenarioConResultado(bool esExitoso);

    int escenarioCompletados() const;
    int escenarioFallidos() const;

    int escenariosExitosos() const;

    string imprimible() const;

private:
    int cantidadEscenariosCompletados = 0;
    int cantidadEscenariosFallidos = 0;
    int cantidadEscenariosExitosos = 0;
};


#endif //CHIL_RESUMEN_H
