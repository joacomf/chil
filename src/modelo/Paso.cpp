#include <modelo/Paso.h>

/**
 * @brief
 * Clase para definir un paso nuevo a partir de una método booleano
 *
 * @class Paso
 *
 * @param const char* nombre - Nombre a otorgar al paso
 * @param bool (*void) funcion - Referencia al metodo que contiene la logica del paso a ser ejecutada
 */
Paso::Paso(const char *nombre, bool (*funcion)()) {
  this->nombre = nombre;
  this->ejecutor = new EjecutorSimple(this, funcion);
}

/**
 * @brief
 * Clase para definir un paso nuevo a partir de un metodo que retorna void pero que lanza excepción
 *
 * @class Paso
 *
 * @param const char* nombre - Nombre a otorgar al paso
 * @param bool (*void) funcion - Referencia al metodo que contiene la logica del paso a ser ejecutada
 */
Paso::Paso(const char *nombre, void (*funcion)()) {
    this->nombre = nombre;
    this->ejecutor = new EjecutorConManejoDeErrores(this, funcion);
}

/**
 * @brief
 * Metodo para saber el tiempo que tomo en ejecutar el paso
 *
 * @return [out][unsigned long] tiempo total de la ejecucion del paso en microsegundos.
 */
unsigned long Paso::tiempo() const {
  return this->tiempoFin - this->tiempoInicio;
}

/**
 * @brief
 * Registra el tiempo de inicio de ejecucion del paso en microsegundos
 *
 * @param long microsegundos tiempo actual en microsegundos
 */
void Paso::inicio(unsigned long microsegundos) {
  this->tiempoInicio = microsegundos;
}

/**
 * @brief
 * Registra el tiempo de fin de ejecucion del paso en microsegundos
 *
 * @param long microsegundos tiempo actual en microsegundos
 */
void Paso::fin(unsigned long microsegundos) {
  this->tiempoFin = microsegundos;
}

/**
 * @brief
 * Elabora el resultado de un paso
 *
 * @return [out][string] Reporte del paso con el tiempo y el resultado del mismo.
 */
string Paso::mostrar() {
    string mensajeExito = this->exitoso ? INDICADOR_PASO_EXITOSO : INDICADOR_PASO_FALLIDO;
    string mensajeTiempo = aTexto(this->tiempo());

    string reporte = mensajeExito.append(this->nombre)
          .append(INDICADOR_TIEMPO_EJECUCION)
          .append(mensajeTiempo).append(UNIDAD_MICROSEGUNDOS);

    if (this->hayMensajeDeError){
        reporte.append(INDICADOR_DETALLE)
               .append(this->mensajeDeDetalleError);
    }

    return reporte;
}

/**
 * @brief
 * Ejecuta el metodo que contiene la logica del paso y establece el resultado como informacion del paso
 */
void Paso::ejecutar() {
    this->ejecutor->ejecutar();
}

/**
 * @brief
 * Obtiene el nombre del paso
 */
string Paso::obtenerNombre() {
  return this->nombre;
}

/**
 * @brief
 * Devuelve si el paso fue exitoso o no
 */
bool Paso::esExitoso() {
    return this->exitoso;
}

/**
 * @brief
 * Guarda si el paso fue exitoso o no
 */
void Paso::esExitoso(bool resultado) {
    this->exitoso = resultado;
}

string Paso::detalleDeError() {
    return this->mensajeDeDetalleError;
}

void Paso::huboError(const char* mensaje) {
    this->hayMensajeDeError = true;
    this->mensajeDeDetalleError = mensaje;
}
