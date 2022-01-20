#include "ValorVerificable.h"

ValorVerificable::ValorVerificable(int numero) {
    this->valorAVerificar = numero;
}

void ValorVerificable::esIgualA(int valorAVerificar) {
    if (this->valorAVerificar != valorAVerificar){
        throw "";
    }
}
