#include "modelo/Acciones.h"

Acciones::Acciones(Framework *framework) : framework(framework) {}

void Acciones::envioComandoDeAltoAl(int pin) {
  framework->escribir(pin, Acciones::COMANDO_ALTO);
}
