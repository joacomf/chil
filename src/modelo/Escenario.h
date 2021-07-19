#ifndef CHIL_ESCENARIO_H
#define CHIL_ESCENARIO_H

#include <list>
#include <string>
#include <modelo/Paso.h>
#include <Plataforma.h>

using namespace std;

class Escenario {

public:
    Escenario(const char *nombre);
    const char *nombre;

    string imprimirResultado();

    void nuevo(Paso *paso);

    int obtenerCantidadPasos();

    void finalizar(Plataforma *framework);

    bool esExitoso();

private:
    list<Paso> _pasos;
    bool exitoso = true;

    constexpr static const char *const INDICADOR_ESCENARIO_FALLIDO = "*** ESCENARIO FALLIDO ***\n";
    constexpr static const char *const COMIENZO_DE_ESCENARIO = "Escenario: ";
    constexpr static const char *const SALTO_DE_LINEA_DOBLE = "\n\n";
    constexpr static const char *const SALTO_DE_LINEA = "\n";
};


#endif //CHIL_ESCENARIO_H
