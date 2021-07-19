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

    string mostrar();

    void ejecutar();

    string obtenerNombre();

    unsigned long tiempo() const;

    void exito(bool esExitoso);
    bool esExitoso();

private:
    const char *nombre;
    bool (*_funcion)();

    bool exitoso = true;

    unsigned long tiempoFin = 0;
    unsigned long tiempoInicio = 0;

};


#endif
