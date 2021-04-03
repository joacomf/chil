#include "../include/Chil.h"

Chil::Chil(Plataforma* framework) {
  this->framework = framework;
}

void Chil::escenario(const char *nombre) {
  this->_escenario = new Escenario(nombre);
}

void Chil::finalizarEscenario() {
  this->_escenario->finalizar(framework);
  this->_escenarios.push_back(*this->_escenario);
}

string Chil::imprimir_reporte() {
  string reporteFinal = string();

  list<Escenario>::iterator escenario;

  for (escenario = this->_escenarios.begin(); escenario != this->_escenarios.end(); ++escenario) {
    reporteFinal.append(escenario->imprimirResultado());
    reporteFinal.append("\n");
  }

  return reporteFinal;
}

void Chil::paso(Paso *paso) {
  _escenario->nuevo(paso);
}
