#ifndef CHIL_CHIL_H
#define CHIL_CHIL_H

#include "Plataforma.h"
#include "modelo/Escenario.h"

#include <list>
#include <string>

using namespace std;

class Chil {

protected:
    explicit Chil(Plataforma *framework1);
    ~Chil() = default;

public:
    Chil(Chil &other) = delete;
    void operator=(const Chil &) = delete;

    static Chil* crear(Plataforma *plataforma);
    static Chil *obtener();

    Plataforma* framework;

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
