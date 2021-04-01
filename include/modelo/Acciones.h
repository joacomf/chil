#ifndef CHIL_ACCIONES_H
#define CHIL_ACCIONES_H


#include <framework/Framework.h>

class Acciones {

public:
    explicit Acciones(Framework *framework);

    void envioBanderaDeAltoAl(int pin);

    int leoValorEn(int i);

private:
    Framework* framework;
    const int COMANDO_ALTO = 1;
};


#endif //CHIL_ACCIONES_H
