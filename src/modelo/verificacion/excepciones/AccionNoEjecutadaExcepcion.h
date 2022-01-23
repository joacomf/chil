#ifndef CHIL_ACCIONNOEJECUTADAEXCEPCION_H
#define CHIL_ACCIONNOEJECUTADAEXCEPCION_H

#include <exception>
#include <string>

using std::exception;

class AccionNoEjecutadaExcepcion : public exception {
private:
    constexpr static const char* const PRINCIPIO_MENSAJE = "La accion indicada no se corroboro en el periodo de ";
    constexpr static const char* const INTERVALOR = " con un intervalo de ";
    constexpr static const char* const FINAL_MENSAJE = " entre cada verificacion";
    constexpr static const char* const UNIDAD_TIEMPO = "ms";

    string mensaje{};
public:
    AccionNoEjecutadaExcepcion(int duracion, int intervalo) {
        mensaje = string(PRINCIPIO_MENSAJE);
        mensaje.append(to_string(duracion)).append(UNIDAD_TIEMPO);
        mensaje.append(INTERVALOR);
        mensaje.append(to_string(intervalo)).append(UNIDAD_TIEMPO);
        mensaje.append(FINAL_MENSAJE);
    }

    string obtenerMensaje() {
        return this->mensaje;
    }
};

#endif //CHIL_ACCIONNOEJECUTADAEXCEPCION_H
