
#ifndef CHIL_VALORNOESMAYOREXCEPCION_H
#define CHIL_VALORNOESMAYOREXCEPCION_H


template <typename T>
class ValorNoEsMayorExcepcion : public ComparacionExcepcion<T> {
private:
    constexpr static const char *const ESPERADO_TEXTO = "mayor";

public:
    explicit ValorNoEsMayorExcepcion(T recibido, T esperado):
            ComparacionExcepcion<T>(recibido, esperado, ESPERADO_TEXTO){}

};
#endif //CHIL_VALORNOESMAYOREXCEPCION_H
