#ifndef CHIL_VALORVERIFICABLE_H
#define CHIL_VALORVERIFICABLE_H

#include <modelo/verificacion/excepciones/ValoresDistintosExcepcion.h>
#include <modelo/verificacion/excepciones/ValorNoEsMenorExcepcion.h>
#include <modelo/verificacion/excepciones/ValorNoEsMayorExcepcion.h>
#include <modelo/verificacion/excepciones/ValorNoEsMayorOIgualExcepcion.h>
#include <modelo/verificacion/excepciones/ValorNoEsMenorOIgualExcepcion.h>
#include <modelo/verificacion/excepciones/ValorNoEstaEntreExcepcion.h>

template <typename Tipo>
class ValorVerificable {

public:
    explicit ValorVerificable() = default;

    explicit ValorVerificable(Tipo elValorAVerificar);

    void esVerdadero();
    void esFalso();

    void esIgualA(Tipo valorEsperado);
    void esMayorA(Tipo valorConElCualComparar);
    void esMenorA(Tipo valorConElCualComparar);
    void esMayorOIgualA(Tipo valorConElCualComparar);
    void esMenorOIgualA(Tipo valorConElCualComparar);

    void entre(Tipo valorInferior, Tipo valorSuperior);

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

template<typename Tipo>
void ValorVerificable<Tipo>::esMayorA(Tipo valorConElCualComparar) {
    this->valorEsperado = valorConElCualComparar;

    if (this->valorAVerificar <= this->valorEsperado){
        throw ValorNoEsMayorExcepcion<Tipo>(this->valorAVerificar, this->valorEsperado);
    }
}

template<typename Tipo>
void ValorVerificable<Tipo>::esMenorA(Tipo valorConElCualComparar) {
    this->valorEsperado = valorConElCualComparar;

    if (this->valorAVerificar >= this->valorEsperado){
        throw ValorNoEsMenorExcepcion<Tipo>(this->valorAVerificar, this->valorEsperado);
    }
}

template<typename Tipo>
void ValorVerificable<Tipo>::esMayorOIgualA(Tipo valorConElCualComparar) {
    this->valorEsperado = valorConElCualComparar;

    if (this->valorAVerificar < this->valorEsperado){
        throw ValorNoEsMayorOIgualExcepcion<Tipo>(this->valorAVerificar, this->valorEsperado);
    }
}

template<typename Tipo>
void ValorVerificable<Tipo>::esMenorOIgualA(Tipo valorConElCualComparar) {
    this->valorEsperado = valorConElCualComparar;

    if (this->valorAVerificar > this->valorEsperado){
        throw ValorNoEsMenorOIgualExcepcion<Tipo>(this->valorAVerificar, this->valorEsperado);
    }
}

template<typename Tipo>
void ValorVerificable<Tipo>::entre(Tipo valorInferior, Tipo valorSuperior) {
    if (this->valorAVerificar < valorInferior || this->valorAVerificar > valorSuperior){
        throw ValorNoEstaEntreExcepcion<Tipo>(this->valorAVerificar, valorInferior, valorSuperior);
    }
}


#endif //CHIL_VALORVERIFICABLE_H


