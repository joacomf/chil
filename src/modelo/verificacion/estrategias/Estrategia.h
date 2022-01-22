#ifndef CHIL_ESTRATEGIA_H
#define CHIL_ESTRATEGIA_H

template <typename T>
class ValorVerificable;

template<typename T>
class Estrategia {
public:
    virtual void verificar(ValorVerificable<T>* valor) = 0;
};

#endif //CHIL_ESTRATEGIA_H
