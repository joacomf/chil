#include <modelo/Paso.h>

Paso::Paso(const char *nombre, void (*funcion)()) {
  this->nombre = nombre;
  this->_funcion = funcion;
}

unsigned long Paso::tiempo() const {
  return this->tiempoFin - this->tiempoInicio;
}

void Paso::inicio(long microsegundos) {
  this->tiempoInicio = microsegundos;
}

void Paso::fin(long microsegundos) {
  this->tiempoFin = microsegundos;
}

string Paso::mostrar() {
  string mensajeExito = this->esExitoso ? string("[OK] ") : string("[FALLO] ");
  string mensajeTiempo = literal(this->tiempo());

  return mensajeExito.append(this->nombre)
          .append(" - ejecuto en ")
          .append(mensajeTiempo).append(" useg");
}

void Paso::ejecutar() {
  this->_funcion();
}

string Paso::obtenerNombre() {
  return this->nombre;
}

void Paso::exito(bool esExitoso) {
  this->esExitoso = esExitoso;
}
