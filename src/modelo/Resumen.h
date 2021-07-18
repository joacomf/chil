#ifndef CHIL_RESUMEN_H
#define CHIL_RESUMEN_H

#include <modelo/Escenario.h>

class Resumen {

public:
    void registrarEscenarioConResultado(bool esExitoso);

    int escenarioCompletados();

private:
    int cantidadEscenariosCompletados = 0;
};


#endif //CHIL_RESUMEN_H
