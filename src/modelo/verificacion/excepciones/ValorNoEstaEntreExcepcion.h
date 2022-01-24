
#ifndef CHIL_VALORNOESTAENTREEXCEPCION_H
#define CHIL_VALORNOESTAENTREEXCEPCION_H
#include <exception>
#include <string>
#include <utilidades/literales.h>

using namespace std;
using literales::aTexto;
using literales::formato;

template <typename T>
class ValorNoEstaEntreExcepcion : public exception {

private:
    constexpr static const char *const TEXTO = "Se esperaba el valor: \n%s\nEste entre: \n%s y %s\nPero no lo esta\n";

    string mensaje{};
public:
    ValorNoEstaEntreExcepcion(T recibido, T inferior, T superior) {
        mensaje = formato(TEXTO,
                          aTexto(recibido).c_str(),
                          aTexto(inferior).c_str(),
                          aTexto(superior).c_str());
    }

    string obtenerMensaje() {
        return mensaje;
    }

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};
#endif //CHIL_VALORNOESTAENTREEXCEPCION_H
