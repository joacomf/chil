
#ifndef CHIL_EJECUTORSIMPLE_H
#define CHIL_EJECUTORSIMPLE_H

#include "Ejecutor.h"
#include <modelo/Paso.h>

class EjecutorSimple: public Ejecutor{
public:
    EjecutorSimple(Paso *paso, bool (*funcion)());

    void ejecutar() override;

private:
    bool (*funcion)();
};


#endif //CHIL_EJECUTORSIMPLE_H
