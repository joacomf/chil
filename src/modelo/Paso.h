#ifndef CHIL_PASO_H
#define CHIL_PASO_H

#include <string>
#include <utils/stringUtils.h>

using namespace std;

class Paso {
public:
    Paso(const char *nombre, bool (*funcion)());

    void inicio(long microsegundos);
    void fin(long microsegundos);

    string obtenerNombre();
    string mostrar();
    void ejecutar();
    unsigned long tiempo() const;
    bool esExitoso();

private:
    constexpr static const char *const INDICADOR_ESCENARIO_EXITOSO = "[OK] ";
    constexpr static const char *const INDICADOR_ESCENARIO_FALLIDO = "[FALLO] ";
    constexpr static const char *const INDICADOR_TIEMPO_EJECUCION = " - ejecuto en ";
    constexpr static const char *const UNIDAD_MICROSEGUNDOS = " useg";

    const char *nombre;
    bool (*_funcion)();

    bool exitoso = true;

    unsigned long tiempoFin = 0;
    unsigned long tiempoInicio = 0;

};


#endif
