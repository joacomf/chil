#include <modelo/Escenario.h>
#include <macros.h>

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
  this->_pasos.push_back(paso);
}

/**
 * Genera el reporte del escenario con el reporte de cada uno de sus pasos
 *
 * @return [out][string] resultado final formateado para mostrar por consola.
 */
string Escenario::imprimirResultado() {
  string reporteDeEscenario = string(COMIENZO_DE_ESCENARIO + string(this->nombre));
  reporteDeEscenario.append(SALTO_DE_LINEA_DOBLE);

  for (Paso *paso : this->_pasos) {
    reporteDeEscenario.append(paso->mostrar());
    reporteDeEscenario.append(SALTO_DE_LINEA);
  }

  if (!this->exitoso) {
    reporteDeEscenario.append(INDICADOR_ESCENARIO_FALLIDO);
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
void Escenario::finalizar() {
  for (Paso *paso : this->_pasos) {
    paso->inicio(PLATAFORMA->microsegundos());
    paso->ejecutar();
    paso->fin(PLATAFORMA->microsegundos());

    bool resultadoDelPaso = paso->esExitoso();

    this->exitoso = this->exitoso && resultadoDelPaso;
  }
}

bool Escenario::esExitoso() const {
    return this->exitoso;
}

