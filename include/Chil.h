#ifndef CHIL_CHIL_H
#define CHIL_CHIL_H

#include "framework/Framework.h"
#include "modelo/Escenario.h"

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


#include "macros.h"


#endif //CHIL_CHIL_H
