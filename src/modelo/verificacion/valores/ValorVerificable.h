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

/**
 * @brief
 * Constructor de Valor verificable
 *
 * @details
 * Declara las acciones a realizar al crear un nuevo valor verificable.
 * La acción realizada es inicializar el campo ValorVerificable::valorAVerificar
 *
 * @tparam Tipo - valor a verificar
 * @return [out][ValorVerificable<Tipo>*] objeto para realizar las comparaciones.
 */
template<typename Tipo>
ValorVerificable<Tipo>::ValorVerificable(Tipo elValorAVerificar) {
    this->valorAVerificar = elValorAVerificar;
}

/**
 * @brief
 * Corrobora si el valor a verificar es igual al dado
 *
 * @details
 * Compara si el valor a verificar es igual al valor esperado pasado por parametro,
 * en caso de que no se cumpla la condición se lanza una ValoresDistintosExcepcion
 *
 * @throw ValoresDistintosExcepcion<Tipo>
 * @tparam Tipo - valor con el cual comparar
 */
template <typename Tipo>
void ValorVerificable<Tipo>::esIgualA(Tipo elValorEsperado) {
    this->valorEsperado = elValorEsperado;

    if (this->valorAVerificar != this->valorEsperado){
        throw ValoresDistintosExcepcion<Tipo>(this->valorAVerificar, this->valorEsperado);
    }
}

/**
 * @brief
 * Corrobora si el valor a verificar es mayor al dado
 *
 * @details
 * Compara si el valor a verificar es mayor al valor pasado por parametro,
 * en caso de que no se cumpla la condición se lanza una ValorNoEsMayorExcepcion
 *
 * @throw ValorNoEsMayorExcepcion<Tipo>
 * @tparam Tipo - valor con el cual comparar
 */
template<typename Tipo>
void ValorVerificable<Tipo>::esMayorA(Tipo valorConElCualComparar) {
    this->valorEsperado = valorConElCualComparar;

    if (this->valorAVerificar <= this->valorEsperado){
        throw ValorNoEsMayorExcepcion<Tipo>(this->valorAVerificar, this->valorEsperado);
    }
}

/**
 * @brief
 * Corrobora si el valor a verificar es menor al dado
 *
 * @details
 * Compara si el valor a verificar es menor al valor pasado por parametro,
 * en caso de que no se cumpla la condición se lanza una ValorNoEsMenorExcepcion
 *
 * @throw ValorNoEsMenorExcepcion<Tipo>
 * @tparam Tipo - valor con el cual comparar
 */
template<typename Tipo>
void ValorVerificable<Tipo>::esMenorA(Tipo valorConElCualComparar) {
    this->valorEsperado = valorConElCualComparar;

    if (this->valorAVerificar >= this->valorEsperado){
        throw ValorNoEsMenorExcepcion<Tipo>(this->valorAVerificar, this->valorEsperado);
    }
}

/**
 * @brief
 * Corrobora si el valor a verificar es mayor o igual al dado
 *
 * @details
 * Compara si el valor a verificar es mayor o igual al valor pasado por parametro,
 * en caso de que no se cumpla la condición se lanza una ValorNoEsMayorOIgualExcepcion
 *
 * @throw ValorNoEsMayorOIgualExcepcion<Tipo>
 * @tparam Tipo - valor con el cual comparar
 */
template<typename Tipo>
void ValorVerificable<Tipo>::esMayorOIgualA(Tipo valorConElCualComparar) {
    this->valorEsperado = valorConElCualComparar;

    if (this->valorAVerificar < this->valorEsperado){
        throw ValorNoEsMayorOIgualExcepcion<Tipo>(this->valorAVerificar, this->valorEsperado);
    }
}

/**
 * @brief
 * Corrobora si el valor a verificar es mayor o igual al dado
 *
 * @details
 * Compara si el valor a verificar es menor o igual al valor pasado por parametro,
 * en caso de que no se cumpla la condición se lanza una ValorNoEsMenorOIgualExcepcion
 *
 * @throw ValorNoEsMenorOIgualExcepcion<Tipo>
 * @tparam Tipo - valor con el cual comparar
 */
template<typename Tipo>
void ValorVerificable<Tipo>::esMenorOIgualA(Tipo valorConElCualComparar) {
    this->valorEsperado = valorConElCualComparar;

    if (this->valorAVerificar > this->valorEsperado){
        throw ValorNoEsMenorOIgualExcepcion<Tipo>(this->valorAVerificar, this->valorEsperado);
    }
}

/**
 * @brief
 * Corrobora si el valor a verificar esta entre dos valores dados [incluidos]
 *
 * @details
 * Compara si el valor a verificar es mayor o igual al primer paramatro y menor o igual al segundo parámetro,
 * en caso de que no se cumpla alguna de las dos condiciones
 * condición se lanza una ValorNoEstaEntreExcepcion
 *
 * @throw ValorNoEsMenorOIgualExcepcion<Tipo>
 * @tparam Tipo - valor con el cual comparar
 */
template<typename Tipo>
void ValorVerificable<Tipo>::entre(Tipo valorInferior, Tipo valorSuperior) {
    if (this->valorAVerificar < valorInferior || this->valorAVerificar > valorSuperior){
        throw ValorNoEstaEntreExcepcion<Tipo>(this->valorAVerificar, valorInferior, valorSuperior);
    }
}


#endif //CHIL_VALORVERIFICABLE_H


