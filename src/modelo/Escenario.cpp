#include <modelo/Escenario.h>

/**
 * Clase para definir un escenario nuevo
 *
 * @class Escenario
 *
 * @param const char* nombre - Nombre a otorgar al escenario
 */
Escenario::Escenario(const char *nombre) {
  this->nombre = nombre;
}

/**
 * Registra un paso definido al escenario en cuestion
 *
 * @param Paso* paso - referencia del paso a registrar en el escenario actual
 */
void Escenario::nuevo(Paso *paso) {
  this->_pasos.push_back(*paso);
}

/**
 * Genera el reporte del escenario con el reporte de cada uno de sus pasos
 *
 * @return [out][string] resultado final formateado para mostrar por consola.
 */
string Escenario::imprimirResultado() {
  list<Paso>::iterator paso;
  string reporteDeEscenario = string("Escenario: " + string(this->nombre));
  reporteDeEscenario.append("\n\n");

  for (paso = this->_pasos.begin(); paso != this->_pasos.end(); ++paso) {
    reporteDeEscenario.append(paso->mostrar());
    reporteDeEscenario.append("\n");
  }

  if (!this->exitoso) {
    reporteDeEscenario.append("*** ESCENARIO FALLIDO ***");
  }

  return reporteDeEscenario;
}

/**
 * Metodo para obtener la cantidad de pasos contenidos en el escenario
 *
 * @return [out][int] cantidad de pasos del escenario.
 */
int Escenario::obtenerCantidadPasos() {
  return this->_pasos.size();
}

/**
 * Comanda finalizar la construccion del escenario y asi ejecutar cada paso contenido tomando los tiempos de ejecuciom
 *
 * @param Plataforma* framework - referencia a la plataforma para poder usar comandos propios de la misma
 */
void Escenario::finalizar(Plataforma *framework) {
  list<Paso>::iterator paso;

  for (paso = this->_pasos.begin(); paso != this->_pasos.end(); ++paso) {
    paso->inicio(framework->microsegundos());
    paso->ejecutar();
    paso->fin(framework->microsegundos());

    this->exitoso = this->exitoso && paso->esExitoso();
  }
}

bool Escenario::esExitoso() {
    return this->exitoso;
}

