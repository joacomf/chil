
#ifndef CHIL_VALORESMAYOREXCEPTION_H
#define CHIL_VALORESMAYOREXCEPTION_H


template <typename T>
class ValorEsMayorExcepcion : public ComparacionExcepcion<T> {
private:
    constexpr static const char *const ESPERADO_TEXTO = "menor";

public:
    explicit ValorEsMayorExcepcion(T recibido, T esperado):
            ComparacionExcepcion<T>(recibido, esperado, ESPERADO_TEXTO){}

};
#endif //CHIL_VALORESMAYOREXCEPTION_H
