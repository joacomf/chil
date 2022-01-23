
#ifndef CHIL_VALORESMENOREXCEPCION_H
#define CHIL_VALORESMENOREXCEPCION_H

#include <exception>
#include <string>
#include <utilidades/literales.h>

using std::exception;
using std::string;
using literales::aTexto;

template <typename T>
class ValorEsMenorExcepcion : public exception {

private:
    constexpr static const char *const TEXTO_ESPERADO = "Se esperaba el valor: ";
    constexpr static const char *const TEXTO_RECIBIDO = "Sea mayor a: ";
    constexpr static const char *const TEXTO_FINAL = "Pero es menor o igual";
    constexpr static const char *const SALTO_DE_LINEA = "\n";

    string mensaje{};

public:
    explicit ValorEsMenorExcepcion(T recibido, T esperado) {
        mensaje.append(TEXTO_ESPERADO).append(SALTO_DE_LINEA);
        mensaje.append(aTexto(esperado)).append(SALTO_DE_LINEA);
        mensaje.append(TEXTO_RECIBIDO).append(SALTO_DE_LINEA);
        mensaje.append(aTexto(recibido)).append(SALTO_DE_LINEA);
        mensaje.append(TEXTO_FINAL).append(SALTO_DE_LINEA);
    }

    string obtenerMensaje() {
        return mensaje;
    }
};
#endif //CHIL_VALORESMENOREXCEPCION_H
