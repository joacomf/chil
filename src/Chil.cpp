#include "../include/Chil.h"

/**
 * Clase principal del framework para escribir pruebas
 *
 * @class Chil
 *
 * @param Plataforma* framework - Instancia del framework de desarrollo soportado por la placa para comunicarse.
 * Por el momento solo existe la implementacion de PlataformaArduino @see FrameworkArduino
 */
Chil::Chil(Plataforma* framework) {
  this->framework = framework;
}

/**
 * Registra un escenario de prueba con el nombre indicado.
 *
 * @param string nombre - nombre del escenario a definir
 */
void Chil::escenario(const char *nombre) {
  this->_escenario = new Escenario(nombre);
}


/**
 * Registra el la finalizacion de un escenario. Lo agrega a los escenarios completados para el reporte a posteriori
 *
 */
void Chil::finalizarEscenario() {
  this->_escenario->finalizar(framework);
  this->_escenarios.push_back(*this->_escenario);
}

/**
 * Genera el reporte de todos los tests ejecutados.
 *
 * @return [out][string] resultado final formateado para mostrar por consola.
 */
string Chil::imprimir_reporte() {
  string reporteFinal = string();

  list<Escenario>::iterator escenario;

  for (escenario = this->_escenarios.begin(); escenario != this->_escenarios.end(); ++escenario) {
    reporteFinal.append(escenario->imprimirResultado());
    reporteFinal.append("\n");
  }

  return reporteFinal;
}

/**
 * Vincula un paso al ultimo escenario registrado que no finalizo
 *
 * @param Paso* paso - referencia del paso a registrar en el escenario actual
 */
void Chil::paso(Paso *paso) {
  _escenario->nuevo(paso);
}
