#ifndef CHIL_VALORVERIFICABLE_H
#define CHIL_VALORVERIFICABLE_H

#include <modelo/verificacion/excepciones/ValoresDistintosExcepcion.h>

template <typename Tipo>
struct ValorVerificable {

public:
    explicit ValorVerificable() {}

    explicit ValorVerificable(Tipo elValorAVerificar);
    void esIgualA(Tipo valorEsperado);

    Tipo obtenerValorEsperado();
    Tipo obtenerValorAVerificar();

private:
    Tipo valorAVerificar{};
    Tipo valorEsperado{};
};


template<typename Tipo>
ValorVerificable<Tipo>::ValorVerificable(Tipo elValorAVerificar) {
    this->valorAVerificar = elValorAVerificar;
}

template <typename Tipo>
void ValorVerificable<Tipo>::esIgualA(Tipo elValorEsperado) {
    this->valorEsperado = elValorEsperado;
    if (this->valorAVerificar != this->valorEsperado){
        throw ValoresDistintosExcepcion<Tipo>(this->valorAVerificar, this->valorEsperado);
    }
}

template <typename Tipo>
Tipo ValorVerificable<Tipo>::obtenerValorEsperado() {
    return this->valorEsperado;
}

template <typename Tipo>
Tipo ValorVerificable<Tipo>::obtenerValorAVerificar() {
    return this->valorAVerificar;
}


#endif //CHIL_VALORVERIFICABLE_H


