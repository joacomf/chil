#include "Verificacion.h"

/**
 * @brief
 * Crea un AccionVerificable para comparar
 * @see AccionVerificable
 *
 * @details
 * Método para crear una nueva AccionVerificable lo que permite pasar una función que retorne un bool
 * para hacer sondeo sobre un bloque de código y corroborar si el mismo se cumple o no.
 *
 * @tparam bool (*funcion)() - función a verificar
 * @return [out][AccionVerificable] objeto para configurar los detalles de la comprobación y realizarla.
 */
AccionVerificable *comprobar(bool (*funcion)()) {
    return new AccionVerificable(funcion);
}
