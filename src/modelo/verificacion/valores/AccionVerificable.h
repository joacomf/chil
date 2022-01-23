#ifndef CHIL_ACCIONVERIFICABLE_H
#define CHIL_ACCIONVERIFICABLE_H

#include <Chil.h>
#include <modelo/verificacion/excepciones/AccionNoEjecutadaExcepcion.h>

class AccionVerificable {

public:
    explicit AccionVerificable(bool (*accionAVerificar)());

    AccionVerificable* durante(int milisegundos);
    AccionVerificable* conIntervaloDe(int intervaloEnMilisegundos);

    void seHayaEjecutado();

private:
    bool (*accionAVerificar)();
    int tiempoLimite = 1000;
    int intervaloEnMilisegundos = 1;
};


#endif //CHIL_ACCIONVERIFICABLE_H
