
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
    constexpr static const char *const TEXTO_ESPERADO = "Se esperaba que el valor ";
    constexpr static const char *const TEXTO_SEA = " sea ";
    constexpr static const char *const TEXTO_A = " a ";
    constexpr static const char *const TEXTO_FINAL = " pero no lo fue";

    string mensaje{};
public:
    ComparacionExcepcion(T recibido, T esperado, const char* textoEsperado) {
        mensaje.append(TEXTO_ESPERADO)
               .append(aTexto(recibido))
               .append(TEXTO_SEA).append(textoEsperado).append(TEXTO_A)
               .append(aTexto(esperado))
               .append(TEXTO_FINAL);
    }

    string obtenerMensaje() {
        return mensaje;
    }

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};


#endif //CHIL_COMPARACIONEXCEPCION_H
