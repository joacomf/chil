#ifndef CHIL_PASO_H
#define CHIL_PASO_H

#include <string>
#include <utilidades/literales.h>
#include <modelo/ejecutores/Ejecutor.h>
#include <modelo/ejecutores/EjecutorSimple.h>
#include <modelo/ejecutores/EjecutorConManejoDeErrores.h>

using namespace std;
using literales::aTexto;

class Paso {
public:
    Paso(const char *nombre, bool (*funcion)());
    Paso(const char *nombre, void (*funcion)());

    void inicio(unsigned long microsegundos);
    void fin(unsigned long microsegundos);

    string obtenerNombre();
    string mostrar();
    void ejecutar();
    unsigned long tiempo() const;

    bool esExitoso();
    void esExitoso(bool resultado);

    string detalleDeError();

    void huboError(const char *string);

private:
    constexpr static const char *const INDICADOR_PASO_EXITOSO = "[OK] ";
    constexpr static const char *const INDICADOR_PASO_FALLIDO = "[FALLO] ";
    constexpr static const char *const INDICADOR_TIEMPO_EJECUCION = " - ejecuto en ";
    constexpr static const char *const UNIDAD_MICROSEGUNDOS = " useg";
    constexpr static const char *const INDICADOR_DETALLE = "\n\tDetalle: ";

    const char *nombre;
    Ejecutor *ejecutor;

    bool exitoso = true;

    unsigned long tiempoFin = 0;
    unsigned long tiempoInicio = 0;

    string mensajeDeDetalleError{};
    bool hayMensajeDeError = false;
};


#endif
