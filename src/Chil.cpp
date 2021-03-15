#include <string>
#include "../include/Chil.h"
#include "Escenario.h"
#include "Dado.h"

Chil::Chil(Framework* framework) {
  this->framework = framework;
}

void Chil::escenario(const char *nombre) {
  this->_escenario = new Escenario(nombre);
}

void Chil::finalizarEscenario() {
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

}
