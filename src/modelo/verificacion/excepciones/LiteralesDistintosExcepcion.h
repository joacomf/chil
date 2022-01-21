#ifndef CHIL_LITERALESDISTINTOSEXCEPCION_H
#define CHIL_LITERALESDISTINTOSEXCEPCION_H

#define SALTO_DE_LINEA "\n"


#include <exception>
#include <string>
#include "modelo/verificacion/valores/ValorVerificable.h"

using std::exception;
using std::string;

class LiteralesDistintosExcepcion : public exception {

private:
    constexpr static const char *const TEXTO_ESPERADO = "Se esperaba el texto: ";
    constexpr static const char *const TEXTO_RECIBIDO = "Pero se recibio el texto: ";

    string mensaje{};

public:
    explicit LiteralesDistintosExcepcion(const char* recibido, const char* esperado) {
        mensaje.append(TEXTO_ESPERADO).append(SALTO_DE_LINEA);
        mensaje.append(esperado);
        mensaje.append(SALTO_DE_LINEA);
        mensaje.append(TEXTO_RECIBIDO).append(SALTO_DE_LINEA);
        mensaje.append(recibido);
        mensaje.append(SALTO_DE_LINEA);
    }

    string obtenerMensaje() {
        return mensaje;
    }
};

#endif //CHIL_LITERALESDISTINTOSEXCEPCION_H
