#ifndef CHIL_CHIL_H
#define CHIL_CHIL_H

#include "Plataforma.h"
#include "modelo/Escenario.h"

#include <list>
#include <string>

#define NUEVO_CHIL_CON(framework) Chil::crear(plataforma)
#define CHIL Chil::obtener()
#define PLATAFORMA Chil::obtener()->plataforma

using namespace std;

class Chil {

protected:
    explicit Chil(Plataforma *pPlataforma);
    ~Chil() = default;

public:
    Chil(Chil &other) = delete;
    void operator=(const Chil &) = delete;

    static Chil* crear(Plataforma *plataforma);
    static Chil *obtener();

    Plataforma* plataforma;

    string imprimirReporte();
    void escenario(const char *nombre);

    void finalizarEscenario();

    void paso(Paso *paso);

private:
    Escenario *_escenario;
    list<Escenario> _escenarios;
};


#include "macros.h"


#endif //CHIL_CHIL_H
