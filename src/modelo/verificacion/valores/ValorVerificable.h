#ifndef CHIL_VALORVERIFICABLE_H
#define CHIL_VALORVERIFICABLE_H

#include <modelo/verificacion/excepciones/ValoresDistintosExcepcion.h>
#include <modelo/verificacion/estrategias/EstrategiaComparacionExacta.h>
#include <modelo/verificacion/excepciones/ValorEsMenorExcepcion.h>
#include <modelo/verificacion/excepciones/ValorEsMayorException.h>

template <typename Tipo>
class ValorVerificable {

public:
    explicit ValorVerificable() = default;

    explicit ValorVerificable(Tipo elValorAVerificar);

    Tipo obtenerValorEsperado();
    Tipo obtenerValorAVerificar();

    void esIgualA(Tipo valorEsperado);
    void esVerdadero();
    void esFalso();

    void esMayorA(Tipo valorConElCualComparar);
    void esMenorA(Tipo valorConElCualComparar);

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
    EstrategiaComparacionExacta<Tipo>().verificar(this);
}

template <typename Tipo>
Tipo ValorVerificable<Tipo>::obtenerValorEsperado() {
    return this->valorEsperado;
}

template <typename Tipo>
Tipo ValorVerificable<Tipo>::obtenerValorAVerificar() {
    return this->valorAVerificar;
}

template<typename Tipo>
void ValorVerificable<Tipo>::esMayorA(Tipo valorConElCualComparar) {
    this->valorEsperado = valorConElCualComparar;

    if (this->valorAVerificar <= this->valorEsperado){
        throw ValorEsMenorExcepcion<Tipo>(this->valorAVerificar, this->valorEsperado);
    }
}

template<typename Tipo>
void ValorVerificable<Tipo>::esMenorA(Tipo valorConElCualComparar) {
    this->valorEsperado = valorConElCualComparar;

    if (this->valorAVerificar >= this->valorEsperado){
        throw ValorEsMayorExcepcion<Tipo>(this->valorAVerificar, this->valorEsperado);
    }
}


#endif //CHIL_VALORVERIFICABLE_H


