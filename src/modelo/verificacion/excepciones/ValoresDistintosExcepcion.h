
#ifndef CHIL_VALORESDISTINTOSEXCEPCION_H
#define CHIL_VALORESDISTINTOSEXCEPCION_H

#define SALTO_DE_LINEA "\n"

#include <exception>
#include <string>

using std::exception;
using std::string;

namespace literales {
    template<typename T>
    string toString(const T& t) {
        return std::to_string(t);
    }

    string toString(const char* t) {
        return t;
    }

    string toString(const string& t) {
        return t;
    }
}

using literales::toString;

template <typename T>
class ValoresDistintosExcepcion : public exception {

private:
    constexpr static const char *const TEXTO_ESPERADO = "Se esperaba el valor: ";
    constexpr static const char *const TEXTO_RECIBIDO = "Pero se recibio el valor: ";

    string mensaje{};

public:
    explicit ValoresDistintosExcepcion(T recibido, T esperado) {
        mensaje.append(TEXTO_ESPERADO).append(SALTO_DE_LINEA);
        mensaje.append(toString(esperado));
        mensaje.append(SALTO_DE_LINEA);
        mensaje.append(TEXTO_RECIBIDO).append(SALTO_DE_LINEA);
        mensaje.append(toString(recibido));
        mensaje.append(SALTO_DE_LINEA);
    }

    string obtenerMensaje() {
        return mensaje;
    }
};

#endif //CHIL_VALORESDISTINTOSEXCEPCION_H
