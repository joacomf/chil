#ifndef CHIL_VERIFICACION_H
#define CHIL_VERIFICACION_H

#include "modelo/verificacion/valores/ValorVerificable.h"

template <typename Tipo>
ValorVerificable<Tipo> verificar(Tipo valor) {
    return ValorVerificable<Tipo>(valor);
}


#endif //CHIL_VERIFICACION_H
