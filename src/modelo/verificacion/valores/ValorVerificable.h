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

template<typename Tipo>
ValorVerificable<Tipo>::ValorVerificable(Tipo elValorAVerificar) {
    this->valorAVerificar = elValorAVerificar;
    this->estrategia = new EstrategiaDirectaConValores<Tipo>();
}

template <typename Tipo>
void ValorVerificable<Tipo>::esIgualA(Tipo elValorEsperado) {
    this->valorEsperado = elValorEsperado;
    this->estrategia->verificar(this);
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


