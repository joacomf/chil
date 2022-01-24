
#ifndef CHIL_COMPARACIONEXCEPCION_H
#define CHIL_COMPARACIONEXCEPCION_H


#include <exception>
#include <string>
#include <utilidades/literales.h>

using namespace std;
using literales::aTexto;
using literales::formato;

template <typename T>
class ComparacionExcepcion : public exception {

private:
    constexpr static const char *const TEXTO = "Se esperaba el valor: \n%s\nSea %s a: \n%s\nPero no lo fue\n";
    string mensaje{};

public:
    ComparacionExcepcion(T recibido, T esperado, const char* textoEsperado) {
        mensaje = formato(TEXTO,
                          aTexto(recibido).c_str(),
                          aTexto(textoEsperado).c_str(),
                          aTexto(esperado).c_str());
    }

    string obtenerMensaje() {
        return mensaje;
    }

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};


#endif //CHIL_COMPARACIONEXCEPCION_H
