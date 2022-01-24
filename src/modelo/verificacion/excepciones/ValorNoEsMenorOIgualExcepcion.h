#ifndef CHIL_VALORNOESMENOROIGUALEXCEPCION_H
#define CHIL_VALORNOESMENOROIGUALEXCEPCION_H

template <typename T>
class ValorNoEsMenorOIgualExcepcion : public ComparacionExcepcion<T> {
private:
    constexpr static const char *const ESPERADO_TEXTO = "menor o igual";

public:
    explicit ValorNoEsMenorOIgualExcepcion(T recibido, T esperado):
            ComparacionExcepcion<T>(recibido, esperado, ESPERADO_TEXTO){}

};

#endif //CHIL_VALORNOESMENOROIGUALEXCEPCION_H
