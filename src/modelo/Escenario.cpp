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

int Escenario::obtenerCantidadPasos() {
  return this->_pasos.size();
}

void Escenario::finalizar(Plataforma *framework) {
  list<Paso>::iterator paso;

  for (paso = this->_pasos.begin(); paso != this->_pasos.end(); ++paso) {
    paso->inicio(framework->microsegundos());
    paso->ejecutar();
    paso->fin(framework->microsegundos());
  }
}

