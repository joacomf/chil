
#ifndef CHIL_VALORESDISTINTOSEXCEPCION_H
#define CHIL_VALORESDISTINTOSEXCEPCION_H

#define SALTO_DE_LINEA "\n"

#include <exception>
#include <string>
#include "modelo/verificacion/valores/ValorVerificable.h"

using std::exception;
using std::string;

template <typename T>
class ValoresDistintosExcepcion : public exception {

private:
    string mensaje{};

public:
    explicit ValoresDistintosExcepcion(T recibido, T esperado) {
        mensaje.append("Se esperaba el valor: ").append(SALTO_DE_LINEA);
        mensaje.append(std::to_string(esperado));
        mensaje.append(SALTO_DE_LINEA);
        mensaje.append("Pero se recibio el valor: ").append(SALTO_DE_LINEA);
        mensaje.append(std::to_string(recibido));
        mensaje.append(SALTO_DE_LINEA);
    }

    string obtenerMensaje() {
        return mensaje;
    }
};

#endif //CHIL_VALORESDISTINTOSEXCEPCION_H
