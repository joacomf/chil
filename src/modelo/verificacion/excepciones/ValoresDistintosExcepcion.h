
#ifndef CHIL_VALORESDISTINTOSEXCEPCION_H
#define CHIL_VALORESDISTINTOSEXCEPCION_H

#include "ComparacionExcepcion.h"

template <typename T>
class ValoresDistintosExcepcion: public ComparacionExcepcion<T> {

public:
    explicit ValoresDistintosExcepcion(T recibido, T esperado):
             ComparacionExcepcion<T>(recibido, esperado, "igual"){}

};

#endif //CHIL_VALORESDISTINTOSEXCEPCION_H
