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

/**
 * Metodo que utiliza la macro de ESCENARIO para registrar un escenario
 *
 * @param Chil* chil - instancia de Chil para generar las acciones
 * @param const char* nombre - nombre a asignar al escenario
 * @param bool (*funcion)() - Referencia al metodo donde se registran los pasos del escenario
 */
void ejecutarEscenario(Chil *chil, const char *nombre, void (*funcion)(Chil *chil)){
  chil->escenario(nombre);
  funcion(chil);
  chil->finalizarEscenario();
}

#define ESCENARIO_GLOBAL(nombre) for(EscenarioEjecutable e(#nombre); e.haIniciado; e.haIniciado = false)

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


#define ESCENARIO(chil, nombre, block) ejecutarEscenario(chil, nombre, block)
#define PASO(chil, nombre, codigo) ejecutarPaso(chil, nombre, codigo)

#endif //CHIL_MACROS_H
