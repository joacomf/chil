#include <modelo/Paso.h>

/**
 * Clase para definir un paso nuevo
 *
 * @class Escenario
 *
 * @param const char* nombre - Nombre a otorgar al paso
 * @param bool (*void) funcion - Referencia al metodo que contiene la logica del paso a ser ejecutada
 */
Paso::Paso(const char *nombre, bool (*funcion)()) {
  this->nombre = nombre;
  this->_funcion = funcion;
}

/**
 * Metodo para saber el tiempo que tomo en ejecutar el paso
 *
 * @return [out][unsigned long] tiempo total de la ejecucion del paso en microsegundos.
 */
unsigned long Paso::tiempo() const {
  return this->tiempoFin - this->tiempoInicio;
}

/**
 * Registra el tiempo de inicio de ejecucion del paso en microsegundos
 *
 * @param long microsegundos tiempo actual en microsegundos
 */
void Paso::inicio(long microsegundos) {
  this->tiempoInicio = microsegundos;
}

/**
 * Registra el tiempo de fin de ejecucion del paso en microsegundos
 *
 * @param long microsegundos tiempo actual en microsegundos
 */
void Paso::fin(long microsegundos) {
  this->tiempoFin = microsegundos;
}

/**
 * Elabora el resultado de un paso
 *
 * @return [out][string] Reporte del paso con el tiempo y el resultado del mismo.
 */
string Paso::mostrar() {
  string mensajeExito = this->exitoso ? INDICADOR_ESCENARIO_EXITOSO : INDICADOR_ESCENARIO_FALLIDO;
  string mensajeTiempo = literal(this->tiempo());

  return mensajeExito.append(this->nombre)
          .append(INDICADOR_TIEMPO_EJECUCION)
          .append(mensajeTiempo).append(UNIDAD_MICROSEGUNDOS);
}

/**
 * Ejecuta el metodo que contiene la logica del paso y establece el resultado como informacion del paso
 */
void Paso::ejecutar() {
  this->exitoso = this->_funcion();
}

/**
 * Obtiene el nombre del paso
 */
string Paso::obtenerNombre() {
  return this->nombre;
}

/**
 * Devuelve si el paso fue exitoso o no
 */
bool Paso::esExitoso() {
    return this->exitoso;
}
