#ifndef CHIL_RESUMEN_H
#define CHIL_RESUMEN_H

#include <modelo/Escenario.h>

class Resumen {

public:
    void registrarEscenarioConResultado(bool esExitoso);

    int escenarioCompletados() const;
    int escenarioFallidos() const;

    int escenariosExitosos() const;

private:
    int cantidadEscenariosCompletados = 0;
    int cantidadEscenariosFallidos = 0;
    int cantidadEscenariosExitosos = 0;
};


#endif //CHIL_RESUMEN_H
