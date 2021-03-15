//
// Created by jmorenof on 15/3/21.
//

#ifndef CHIL_ESCENARIO_H
#define CHIL_ESCENARIO_H

#include <string>
using namespace std;

class Escenario {

public:
    Escenario(const char *nombre);
    const char *nombre;

    string imprimirResultado() const;
};


#endif //CHIL_ESCENARIO_H
