#ifndef CHIL_VERIFICACION_H
#define CHIL_VERIFICACION_H

#include "modelo/verificacion/valores/ValorVerificable.h"
#include "modelo/verificacion/valores/AccionVerificable.h"

AccionVerificable* comprobar(bool (*funcion)());

/**
 * @brief
 * Crea un ValorVerificable para comparar
 * @see ValorVerificable
 *
 * @details
 * Método para crear un nuevo ValorVerificable<Tipo> siendo Tipo cualquier tipo permitido
 * del lenguaje para poder hacerle comparaciones con otro valor del mismo tipo
 * (ej: ValorVerificable::igualA)
 *
 * @tparam Tipo - valor a verificar
 * @return [out][ValorVerificable<Tipo>*] objeto para realizar las comparaciones.
 */
template <typename Tipo>
ValorVerificable<Tipo>* verificar(Tipo valor) {
    return new ValorVerificable<Tipo>(valor);
}

#endif //CHIL_VERIFICACION_H
