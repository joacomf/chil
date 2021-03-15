#include <modelo/Escenario.h>

Escenario::Escenario(const char *nombre) {
  this->nombre = nombre;
}

void Escenario::nuevo(Paso *paso) {
  this->_pasos.push_back(*paso);
}

string Escenario::imprimirResultado() {
  list<Paso>::iterator paso;
  string reporteDeEscenario = string("Escenario: " + string(this->nombre));
  reporteDeEscenario.append("\n\n");

  for (paso = this->_pasos.begin(); paso != this->_pasos.end(); ++paso) {
    reporteDeEscenario.append(paso->mostrar());
    reporteDeEscenario.append("\n");
  }

  return reporteDeEscenario;
}

