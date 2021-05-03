#include "utils/stringUtils.h"

/**
 * Metodo para generar un literal (string) de un valor int soportado por los compiladores de los microcontroladores
 *
 * @param int valor - valor a convertir
 * @return [out][string] valor convertido a string.
 */
string literal(int valor) {
  char buffer[256];

  sprintf(buffer, "%d", valor);

  return string(buffer);
}

/**
 * Metodo para generar un literal (string) de un valor unsiged long soportado por los compiladores de los microcontroladores
 *
 * @param unsigned long valor - valor a convertir
 * @return [out][string] valor convertido a string.
 */
string literal(unsigned long valor) {
  char buffer[256];

  sprintf(buffer, "%lu", valor);

  return string(buffer);
}