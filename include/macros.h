#ifndef CHIL_MACROS_H
#define CHIL_MACROS_H

#include "modelo/Paso.h"
#include "Chil.h"

void ejecutarPaso(Chil *chil, const char *nombre, bool (*funcion)()) {
  Paso *paso = new Paso(nombre, funcion);
  chil->paso(paso);
}

void ejecutarEscenario(Chil *chil, const char *nombre, void (*funcion)(Chil *chil)){
  chil->escenario(nombre);
  funcion(chil);
  chil->finalizarEscenario();
}

#define ESCENARIO(chil, nombre, block) ejecutarEscenario(chil, nombre, block)
#define PASO(chil, nombre, codigo) ejecutarPaso(chil, nombre, codigo)

#endif //CHIL_MACROS_H
