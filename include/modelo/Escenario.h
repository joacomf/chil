#ifndef CHIL_ESCENARIO_H
#define CHIL_ESCENARIO_H

#include <list>
#include <string>
#include <modelo/Paso.h>
#include <plataforma/Plataforma.h>

using namespace std;

class Escenario {

public:
    Escenario(const char *nombre);
    const char *nombre;

    string imprimirResultado();

    void nuevo(Paso *paso);

    int obtenerCantidadPasos();

    void finalizar(Plataforma *framework);

private:
    list<Paso> _pasos;
};


#endif //CHIL_ESCENARIO_H
