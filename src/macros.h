#ifndef CHIL_MACROS_H
#define CHIL_MACROS_H

#include "Chil.h"
#include "modelo/Paso.h"

#define ESCENARIO(nombre) for(EscenarioEjecutable e(#nombre); e.haIniciado; e.haIniciado = false)

/**
 * @class EscenarioEjecutable
 *
 * Esta clase se utiliza para utilizar en la macro ESCENARIO y así aprovechar el poder del constructor para iniciar un
 * escenario nuevo en chil, luego se ejecuta el cuerpo del macro y al final se llama al destructor, que se encarga de
 * finalizar el escenario, debido a que la instancia queda sin utilizar y la limpia el garbage collector
 */
class EscenarioEjecutable {
public:
    bool haIniciado;
    explicit EscenarioEjecutable(const char* nombre);
    ~EscenarioEjecutable();
};


#define PASO(nombre, funcion) for(PasoEjecutable p(#nombre, funcion); p.haIniciado; p.haIniciado = false)

/**
 * @class PasoEjecutable
 *
 * Esta clase se utiliza para utilizar en la macro PASO y así aprovechar el poder del constructor para iniciar un
 * escenario nuevo en chil, luego se ejecuta el cuerpo del macro y al final se llama al destructor debido a que la
 * instancia queda sin utilizar
 */
class PasoEjecutable {
public:
    bool haIniciado;
    PasoEjecutable(const char* nombre, bool (*funcion)());
    PasoEjecutable(const char* nombre, void (*funcion)());
    ~PasoEjecutable() = default;
};

#endif //CHIL_MACROS_H
