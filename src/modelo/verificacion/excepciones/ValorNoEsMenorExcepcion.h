
#ifndef CHIL_VALORNOESMENOREXCEPCION_H
#define CHIL_VALORNOESMENOREXCEPCION_H

#include <exception>
#include <string>
#include <utilidades/literales.h>

using std::exception;
using std::string;
using literales::aTexto;

template <typename T>
class ValorNoEsMenorExcepcion : public ComparacionExcepcion<T> {
private:
    constexpr static const char *const ESPERADO_TEXTO = "menor";

public:
    explicit ValorNoEsMenorExcepcion(T recibido, T esperado) :
             ComparacionExcepcion<T>(recibido, esperado, ESPERADO_TEXTO){}

};
#endif //CHIL_VALORNOESMENOREXCEPCION_H
