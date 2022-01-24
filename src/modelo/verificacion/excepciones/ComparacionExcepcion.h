
#ifndef CHIL_COMPARACIONEXCEPCION_H
#define CHIL_COMPARACIONEXCEPCION_H


#include <exception>
#include <string>
#include <utilidades/literales.h>

using namespace std;
using literales::aTexto;

template <typename T>
class ComparacionExcepcion : public exception {

private:
    constexpr static const char *const SALTO_DE_LINEA = "\n";
    constexpr static const char *const TEXTO_ESPERADO = "Se esperaba el valor: ";
    constexpr static const char *const TEXTO_SEA = "Sea ";
    constexpr static const char *const TEXTO_A = " a: ";
    constexpr static const char *const TEXTO_FINAL = "Pero no lo fue";

    string mensaje{};
public:
    ComparacionExcepcion(T recibido, T esperado, const char* textoEsperado) {
        mensaje.append(TEXTO_ESPERADO).append(SALTO_DE_LINEA)
               .append(aTexto(esperado)).append(SALTO_DE_LINEA)
               .append(TEXTO_SEA).append(textoEsperado).append(TEXTO_A).append(SALTO_DE_LINEA)
               .append(aTexto(recibido)).append(SALTO_DE_LINEA)
               .append(TEXTO_FINAL).append(SALTO_DE_LINEA);
    }

    string obtenerMensaje() {
        return mensaje;
    }

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};


#endif //CHIL_COMPARACIONEXCEPCION_H
