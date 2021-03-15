#ifndef CHIL_DADO_H
#define CHIL_DADO_H

#include "Paso.h"

class Dado : public Paso{
public:
    Dado(const char *nombre, void (*funcion)());
};


#endif //CHIL_DADO_H
