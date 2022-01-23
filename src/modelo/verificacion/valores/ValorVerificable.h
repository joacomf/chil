#ifndef CHIL_VALORVERIFICABLE_H
#define CHIL_VALORVERIFICABLE_H

#include <modelo/verificacion/excepciones/ValoresDistintosExcepcion.h>
#include <modelo/verificacion/estrategias/EstrategiaDirectaConValores.h>

template <typename Tipo>
class ValorVerificable {

public:
    explicit ValorVerificable() = default;

    explicit ValorVerificable(Tipo elValorAVerificar);
    void esIgualA(Tipo valorEsperado);

    Tipo obtenerValorEsperado();
    Tipo obtenerValorAVerificar();

private:
    Tipo valorAVerificar{};
    Tipo valorEsperado{};

    Estrategia<Tipo>* estrategia{};
};

#include "ValorVerificable.cpp"

#endif //CHIL_VALORVERIFICABLE_H


