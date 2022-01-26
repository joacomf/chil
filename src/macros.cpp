#include "macros.h"

EscenarioEjecutable::EscenarioEjecutable(const char *nombre) {
    CHIL->escenario(nombre);
    haIniciado = true;
}

EscenarioEjecutable::~EscenarioEjecutable() {
    CHIL->finalizarEscenario();
}

PasoEjecutable::PasoEjecutable(const char *nombre, bool (*funcion)()) {
    Paso *paso = new Paso(nombre, funcion);
    CHIL->paso(paso);
    haIniciado = true;
}

PasoEjecutable::PasoEjecutable(const char *nombre, void (*funcion)()) {
    Paso *paso = new Paso(nombre, funcion);
    CHIL->paso(paso);
    haIniciado = true;
}