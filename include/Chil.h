#ifndef CHIL_CHIL_H
#define CHIL_CHIL_H

#include "framework/Framework.h"
#include "Escenario.h"
#include "Dado.h"

#include <list>
#include <string>
using namespace std;

class Chil {

public:
    explicit Chil(Framework *framework);

    Framework *framework;

    string imprimir_reporte();
    void escenario(const char *nombre);

    void finalizarEscenario();

    void paso(Paso *paso);

private:
    Escenario *_escenario;
    list<Escenario> _escenarios;
};


#endif //CHIL_CHIL_H
