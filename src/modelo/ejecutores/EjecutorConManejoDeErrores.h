
#ifndef CHIL_EJECUTORCONMANEJODEERRORES_H
#define CHIL_EJECUTORCONMANEJODEERRORES_H

#include "Ejecutor.h"
#include <modelo/Paso.h>

class EjecutorConManejoDeErrores : public Ejecutor {
public:
    EjecutorConManejoDeErrores(Paso *paso, void (*funcion)());

    void ejecutar() override;

private:
    void (*funcion)();
};


#endif //CHIL_EJECUTORCONMANEJODEERRORES_H
