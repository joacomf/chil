
#ifndef CHIL_ESTRATEGIADIRECTACONVALORES_H
#define CHIL_ESTRATEGIADIRECTACONVALORES_H

#include "Estrategia.h"

template<typename T>
class ValorVerificable;

template <typename Tipo>
class EstrategiaDirectaConValores: public Estrategia<Tipo>{
    void verificar(ValorVerificable<Tipo>* valor) override {
        if (valor->obtenerValorAVerificar() != valor->obtenerValorEsperado()){
            throw ValoresDistintosExcepcion<Tipo>(valor->obtenerValorAVerificar(), valor->obtenerValorEsperado());
        }
    };
};



#endif //CHIL_ESTRATEGIADIRECTACONVALORES_H
