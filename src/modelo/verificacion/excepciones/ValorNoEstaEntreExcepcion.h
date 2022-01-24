
#ifndef CHIL_VALORNOESTAENTREEXCEPCION_H
#define CHIL_VALORNOESTAENTREEXCEPCION_H
#include <exception>
#include <string>
#include <utilidades/literales.h>

using namespace std;
using literales::aTexto;

template <typename T>
class ValorNoEstaEntreExcepcion : public exception {

private:
    constexpr static const char *const SALTO_DE_LINEA = "\n";
    constexpr static const char *const TEXTO_ESPERADO = "Se esperaba el valor: ";
    constexpr static const char *const TEXTO_ENTRE = "Este entre: ";
    constexpr static const char *const TEXTO_Y = " y ";
    constexpr static const char *const TEXTO_FINAL = "Pero no lo esta";

    string mensaje{};
public:
    ValorNoEstaEntreExcepcion(T recibido, T inferior, T superior) {
        mensaje.append(TEXTO_ESPERADO).append(SALTO_DE_LINEA)
                .append(aTexto(recibido)).append(SALTO_DE_LINEA)
                .append(TEXTO_ENTRE).append(SALTO_DE_LINEA)
                .append(aTexto(inferior)).append(TEXTO_Y).append(aTexto(superior)).append(SALTO_DE_LINEA)
                .append(TEXTO_FINAL).append(SALTO_DE_LINEA);
    }

    string obtenerMensaje() {
        return mensaje;
    }

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};
#endif //CHIL_VALORNOESTAENTREEXCEPCION_H
