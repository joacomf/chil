#include "modelo/Escenario.h"

Escenario::Escenario(const char *nombre) {
  this->nombre = nombre;
}

string Escenario::imprimirResultado() const {
  string reporteDeEscenario = string("Escenario: " + string(this->nombre));
  reporteDeEscenario.append("\n\n");

  return reporteDeEscenario;
}
