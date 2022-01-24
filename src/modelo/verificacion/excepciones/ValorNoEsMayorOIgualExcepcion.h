
#ifndef CHIL_VALORNOESMAYOROIGUALEXCEPCION_H
#define CHIL_VALORNOESMAYOROIGUALEXCEPCION_H

template <typename T>
class ValorNoEsMayorOIgualExcepcion : public ComparacionExcepcion<T> {
private:
    constexpr static const char *const ESPERADO_TEXTO = "mayor o igual";

public:
    explicit ValorNoEsMayorOIgualExcepcion(T recibido, T esperado):
            ComparacionExcepcion<T>(recibido, esperado, ESPERADO_TEXTO){}

};
#endif //CHIL_VALORNOESMAYOROIGUALEXCEPCION_H
