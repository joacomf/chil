#ifndef CHIL_VALORVERIFICABLE_H
#define CHIL_VALORVERIFICABLE_H


class ValorVerificable {

public:
    explicit ValorVerificable(int valorAVerificar);
    void esIgualA(int valorEsperado);

private:
    int valorAVerificar;
};


#endif //CHIL_VALORVERIFICABLE_H
