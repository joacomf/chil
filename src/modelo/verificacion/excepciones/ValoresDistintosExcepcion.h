
#ifndef CHIL_VALORESDISTINTOSEXCEPCION_H
#define CHIL_VALORESDISTINTOSEXCEPCION_H

#include "ComparacionExcepcion.h"

template <typename T>
class ValoresDistintosExcepcion: public ComparacionExcepcion<T> {
private:
    constexpr static const char *const ESPERADO_TEXTO = "igual";

public:
    explicit ValoresDistintosExcepcion(T recibido, T esperado):
             ComparacionExcepcion<T>(recibido, esperado, ESPERADO_TEXTO){}

};

#endif //CHIL_VALORESDISTINTOSEXCEPCION_H
