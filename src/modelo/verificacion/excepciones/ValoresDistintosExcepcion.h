
#ifndef CHIL_VALORESDISTINTOSEXCEPCION_H
#define CHIL_VALORESDISTINTOSEXCEPCION_H

#include <exception>
#include <string>
#include "utils/literales.h"

using std::exception;
using std::string;
using literales::aTexto;

template <typename T>
class ValoresDistintosExcepcion : public exception {

private:
    constexpr static const char *const TEXTO_ESPERADO = "Se esperaba el valor: ";
    constexpr static const char *const TEXTO_RECIBIDO = "Pero se recibio el valor: ";
    constexpr static const char *const SALTO_DE_LINEA = "\n";

    string mensaje{};

public:
    explicit ValoresDistintosExcepcion(T recibido, T esperado) {
        mensaje.append(TEXTO_ESPERADO).append(SALTO_DE_LINEA);
        mensaje.append(aTexto(esperado));
        mensaje.append(SALTO_DE_LINEA);
        mensaje.append(TEXTO_RECIBIDO).append(SALTO_DE_LINEA);
        mensaje.append(aTexto(recibido));
        mensaje.append(SALTO_DE_LINEA);
    }

    string obtenerMensaje() {
        return mensaje;
    }
};

#endif //CHIL_VALORESDISTINTOSEXCEPCION_H
