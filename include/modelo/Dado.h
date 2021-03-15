#ifndef CHIL_DADO_H
#define CHIL_DADO_H

#include "Paso.h"

class Dado : public Paso{
public:
    Dado(const char *nombre, bool (*funcion)());
};


#endif //CHIL_DADO_H
