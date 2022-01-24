#include "ValorVerificable.h"

/**
 * @brief
 * Corrobora si el valor a verificar es verdero
 *
 * @details
 * Compara si el valor a verificar es verdadero, en caso de no cumplir la
 * condición se lanza una ValoresDistintosExcepcion
 *
 * @throw ValoresDistintosExcepcion<Tipo>
 */
template<> void ValorVerificable<bool>::esVerdadero() {
    this->esIgualA(true);
}

/**
 * @brief
 * Corrobora si el valor a verificar es falso
 *
 * @details
 * Compara si el valor a verificar es falso, en caso de no cumplir la
 * condición se lanza una ValoresDistintosExcepcion
 *
 * @throw ValoresDistintosExcepcion<Tipo>
 */
template<> void ValorVerificable<bool>::esFalso() {
    this->esIgualA(false);
}