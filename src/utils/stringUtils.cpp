#include "utils/stringUtils.h"

string literal(int valor) {
  char buffer[256];

  sprintf(buffer, "%d", valor);

  return string(buffer);
}

string literal(unsigned long valor) {
  char buffer[256];

  sprintf(buffer, "%lu", valor);

  return string(buffer);
}