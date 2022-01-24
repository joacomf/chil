#include "Verificacion.h"

AccionVerificable *comprobar(bool (*funcion)()) {
    return new AccionVerificable(funcion);
}
