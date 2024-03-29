#include "Chil.h"

Chil *instance_;

/**
 * Clase principal del framework para escribir pruebas
 *
 * @class Chil
 *
 * @param Plataforma* framework - Instancia del framework de desarrollo soportado por la placa para comunicarse.
 * Por el momento solo existe la implementacion de PlataformaArduino @see FrameworkArduino
 */
Chil::Chil(Plataforma* pPlataforma) {
  this->plataforma = pPlataforma;
  this->plataforma->consola(this->mensajeComienzo);
  this->resumen = new Resumen();
}

/**
 * Crea instancia única de chil utilizando la plataforma indicado
 *
 * @class Chil
 *
 * @param Plataforma* framework - Instancia del framework de desarrollo soportado por la placa para comunicarse.
 * Por el momento solo existe la implementacion de PlataformaArduino @see PlataformaArduino
 * @return [out][Chil] instancia de chil creada.
 */
Chil *Chil::crear(Plataforma *plataforma) {
    instance_ = new Chil(plataforma);
    return instance_;
}

/**
* Obitene la instancia única de Chil ya configurada
*
* @class Chil
*
* @param Plataforma* framework - Instancia del framework de desarrollo soportado por la placa para comunicarse.
* Por el momento solo existe la implementacion de PlataformaArduino @see PlataformaArduino
* @return [out][Chil] instancia de chil creada.
*/
Chil *Chil::obtener(){
    return instance_;
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
    this->_escenario->finalizar();
    this->resumen->registrarEscenarioConResultado(this->_escenario->esExitoso());
    this->_escenarios.push_back(this->_escenario);
}

/**
 * Genera el reporte de todos los tests ejecutados.
 *
 * @return [out][string] resultado final formateado para mostrar por consola.
 */
string Chil::imprimirReporte() {
  string reporteFinal = string();

  vector<Escenario*>::const_iterator escenarioIterado;

  for (escenarioIterado = this->_escenarios.begin(); escenarioIterado != this->_escenarios.end(); ++escenarioIterado) {
    reporteFinal.append((*escenarioIterado)->imprimirResultado());
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

/**
 * Muestra el resultado de finalizacion de todas pruebas
 *
 */
void Chil::finalizarPruebas() {
    this->plataforma->consola(this->imprimirReporte().c_str());
    this->plataforma->consola(this->imprimirResumen().c_str());
    this->plataforma->consola(this->mensajeFinDePruebas);
    this->plataforma->consola("\n");
    this->exportarJSON();
}

string Chil::imprimirResumen() {
    return resumen->imprimible();
}

const vector<Escenario *> &Chil::obtenerEscenarios() {
    return this->_escenarios;
}

Resumen *Chil::obtenerResumen() {
    return this->resumen;
}

void Chil::exportarJSON() {
    this->plataforma->consola(ETIQUETA_COMIENZO_JSON);
    this->plataforma->consola(ExportadorJSON::generar().c_str());
    this->plataforma->consola(ETIQUETA_FIN_JSON);
}
