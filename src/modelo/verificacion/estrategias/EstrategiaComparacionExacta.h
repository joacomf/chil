
#ifndef CHIL_ESTRATEGIACOMPARACIONEXACTA_H
#define CHIL_ESTRATEGIACOMPARACIONEXACTA_H

#include "Estrategia.h"

template <typename Tipo>
class EstrategiaComparacionExacta: public Estrategia<Tipo>{
public:
    void verificar(ValorVerificable<Tipo>* valor) override {
        if (valor->obtenerValorAVerificar() != valor->obtenerValorEsperado()){
            throw ValoresDistintosExcepcion<Tipo>(valor->obtenerValorAVerificar(), valor->obtenerValorEsperado());
        }
    };
};



#endif //CHIL_ESTRATEGIACOMPARACIONEXACTA_H
