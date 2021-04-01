#ifndef CHIL_FRAMEWORK_H
#define CHIL_FRAMEWORK_H

class Framework {

public:
    virtual void consola(const char *string) = 0;

    virtual unsigned long microsegundos() = 0;

    virtual void escribir(int pin, int valor) = 0;

    virtual int leer(int pin) = 0;
};


#endif //CHIL_FRAMEWORK_H
