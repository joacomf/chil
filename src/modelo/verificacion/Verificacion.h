#ifndef CHIL_VERIFICACION_H
#define CHIL_VERIFICACION_H

#include "modelo/verificacion/valores/ValorVerificable.h"
#include "modelo/verificacion/valores/AccionVerificable.h"

AccionVerificable* comprobar(bool (*funcion)());

template <typename Tipo>
ValorVerificable<Tipo>* verificar(Tipo valor) {
    return new ValorVerificable<Tipo>(valor);
}

#endif //CHIL_VERIFICACION_H
