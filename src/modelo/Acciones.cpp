#include "modelo/Acciones.h"

Acciones::Acciones(Framework *framework) : framework(framework) {}

void Acciones::envioBanderaDeAltoAl(int pin) {
  framework->escribir(pin, Acciones::COMANDO_ALTO);
}

int Acciones::leoValorEn(int pin) {
  return framework->leer(pin);
}
