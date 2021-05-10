#ifndef CHIL_MACROS_H
#define CHIL_MACROS_H

#include "modelo/Paso.h"
#include "Chil.h"

/**
 * Metodo que utiliza la macro de PASO para generar el paso y registrarlo
 *
 * @param Chil* chil - instancia de Chil para generar las acciones
 * @param const char* nombre - nombre a asignar al paso
 * @param bool (*funcion)() - Referencia al metodo que contiene la logica del paso
 */
void ejecutarPaso(Chil *chil, const char *nombre, bool (*funcion)()) {
  Paso *paso = new Paso(nombre, funcion);
  chil->paso(paso);
}


#define ESCENARIO(nombre) for(EscenarioEjecutable e(#nombre); e.haIniciado; e.haIniciado = false)

/**
 * @class EscenarioEjecutable
 *
 * Esta clase se utiliza para utilizar en la macro ESCENARIO y así aprovechar el poder del constructor para iniciar un
 * escenario nuevo en chil, luego se ejecuta el cuerpo del macro y al final se llama al destructor debido a que la
 * instancia queda sin utilizar y la limpia el garbage collector
 */
class EscenarioEjecutable {
public:
    bool haIniciado;
    EscenarioEjecutable(const char* nombre) {
        CHIL->escenario(nombre);
        haIniciado = true;
    }
    ~EscenarioEjecutable() {
        CHIL->finalizarEscenario();
    }
};


#define PASO(chil, nombre, codigo) ejecutarPaso(chil, nombre, codigo)

#endif //CHIL_MACROS_H
