
#ifndef CHIL_VALORESMENOREXCEPCION_H
#define CHIL_VALORESMENOREXCEPCION_H

#include <exception>
#include <string>
#include <utilidades/literales.h>

using std::exception;
using std::string;
using literales::aTexto;

template <typename T>
class ValorEsMenorExcepcion : public ComparacionExcepcion<T> {
private:
    constexpr static const char *const ESPERADO_TEXTO = "mayor";

public:
    explicit ValorEsMenorExcepcion(T recibido, T esperado) :
             ComparacionExcepcion<T>(recibido, esperado, ESPERADO_TEXTO){}

};
#endif //CHIL_VALORESMENOREXCEPCION_H
