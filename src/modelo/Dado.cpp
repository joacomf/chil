#include "modelo/Dado.h"

Dado::Dado(const char *nombre, bool (*funcion)()) : Paso(nombre, funcion) {
}

