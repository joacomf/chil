#ifndef CHIL_VALORVERIFICABLE_H
#define CHIL_VALORVERIFICABLE_H

template <typename Tipo>
class ValorVerificable {

public:
    explicit ValorVerificable(Tipo elValorAVerificar);
    void esIgualA(Tipo valorEsperado);

    Tipo obtenerValorEsperado();
    Tipo obtenerValorAVerificar();

private:
    Tipo valorAVerificar{};
    Tipo valorEsperado{};
};
#endif //CHIL_VALORVERIFICABLE_H

#include "modelo/verificacion/valores/ValorVerificable.tpp"

