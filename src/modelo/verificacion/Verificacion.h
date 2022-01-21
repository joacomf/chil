#ifndef CHIL_VERIFICACION_H
#define CHIL_VERIFICACION_H

#include "modelo/verificacion/valores/ValorVerificable.h"

template <typename Tipo>
ValorVerificable<Tipo> verificar(Tipo valor) {
    return ValorVerificable<Tipo>(valor);
}

ValorVerificable<const char*> verificarLiteral(const char* texto) {
    return ValorVerificable<const char*>(texto);
}


#endif //CHIL_VERIFICACION_H
