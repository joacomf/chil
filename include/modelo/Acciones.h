#ifndef CHIL_ACCIONES_H
#define CHIL_ACCIONES_H


#include <framework/Framework.h>

class Acciones {

public:
    Acciones(Framework *framework);

    void envioComandoDeAltoAl(int pin);

private:
    Framework* framework;
    const int COMANDO_ALTO = 1;
};


#endif //CHIL_ACCIONES_H
