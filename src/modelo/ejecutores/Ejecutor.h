#ifndef CHIL_EJECUTOR_H
#define CHIL_EJECUTOR_H

class Paso;

class Ejecutor {
public:
    explicit Ejecutor(Paso* paso) {
        this->paso = paso;
    }
    virtual void ejecutar() = 0;

protected:
    Paso *paso{};
};

#endif //CHIL_EJECUTOR_H
