#ifndef CHIL_ACCIONNOEJECUTADAEXCEPCION_H
#define CHIL_ACCIONNOEJECUTADAEXCEPCION_H

#include <exception>
#include <string>

#include <utilidades/literales.h>

using std::exception;
using literales::aTexto;
using literales::formato;

class AccionNoEjecutadaExcepcion : public exception {
private:
    constexpr static const char *const TEXTO = "La accion indicada no se corroboro en el periodo de %sms con un intervalo de %sms entre cada verificacion";
    string mensaje{};

public:
    AccionNoEjecutadaExcepcion(int duracion, int intervalo) {
        mensaje = formato(TEXTO, aTexto(duracion).c_str(), aTexto(intervalo).c_str());
    }

    string obtenerMensaje() {
        return this->mensaje;
    }
};

#endif //CHIL_ACCIONNOEJECUTADAEXCEPCION_H
