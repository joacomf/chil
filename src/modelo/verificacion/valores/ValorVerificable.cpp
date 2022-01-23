#include "ValorVerificable.h"

template<> void ValorVerificable<bool>::esVerdadero() {
    this->esIgualA(true);
}
template<> void ValorVerificable<bool>::esFalso() {
    this->esIgualA(false);
}

