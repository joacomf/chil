#ifndef CHIL_ACCIONES_H
#define CHIL_ACCIONES_H


#include <plataforma/Plataforma.h>

class Acciones {

public:
    explicit Acciones(Plataforma *framework);

    void envioBanderaDeAltoAl(int pin);

    int leoValorEn(int i);

private:
    Plataforma* framework;
    const int COMANDO_ALTO = 1;
};


#endif //CHIL_ACCIONES_H
