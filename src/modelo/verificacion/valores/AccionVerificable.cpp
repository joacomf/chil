#include "AccionVerificable.h"
#include "modelo/verificacion/excepciones/AccionNoEjecutadaExcepcion.h"

AccionVerificable::AccionVerificable(bool (*laAccion)()) {
    this->accionAVerificar = laAccion;
}

AccionVerificable * AccionVerificable::durante(int milisegundos) {
    this->tiempoLimite = milisegundos;
    return this;
}

void AccionVerificable::seHayaEjecutado() {
    unsigned long tiempoInicial = PLATAFORMA->milisegundos();

    while(PLATAFORMA->milisegundos() - tiempoInicial < this->tiempoLimite){
        if(this->accionAVerificar()) {
            return;
        }
    }

    throw AccionNoEjecutadaExcepcion();
}
