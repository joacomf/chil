#ifndef CHIL_ACCIONVERIFICABLE_H
#define CHIL_ACCIONVERIFICABLE_H

#include <Chil.h>

class AccionVerificable {

public:
    explicit AccionVerificable(bool (*accionAVerificar)());
    AccionVerificable * durante(int milisegundos);

    void seHayaEjecutado();

private:
    bool (*accionAVerificar)();
    int tiempoLimite = 1000;
};


#endif //CHIL_ACCIONVERIFICABLE_H
