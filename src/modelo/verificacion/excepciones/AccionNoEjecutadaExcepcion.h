#ifndef CHIL_ACCIONNOEJECUTADAEXCEPCION_H
#define CHIL_ACCIONNOEJECUTADAEXCEPCION_H

#include <exception>
#include <string>

using std::exception;

class AccionNoEjecutadaExcepcion : public exception {
public:
    AccionNoEjecutadaExcepcion() = default;
};

#endif //CHIL_ACCIONNOEJECUTADAEXCEPCION_H
