#include "literales.h"

/**
 * Metodo para convertir a string, es un bypass para la implementación con genéricos
 * en el caso del tipo "const char*" no hay que convertir nada
 *
 * @param const char* texto - valor a convertir
 * @return [out][std::string] valor convertido a string.
 */
string literales::aTexto(const char *t) {
    return t;
}

/**
 * Metodo para convertir a string, es un bypass para la implementación con genéricos
 * en el caso de el tipo "string" no hay que convertir nada
 *
 * @param const T& texto - valor a convertir
 * @return [out][std::string] valor convertido a string.
 */
string literales::aTexto(const string &t) {
    return t;
}
