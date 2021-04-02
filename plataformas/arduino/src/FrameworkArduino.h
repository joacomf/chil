#ifndef CHIL_FRAMEWORKARDUINO_H
#define CHIL_FRAMEWORKARDUINO_H

#include <Arduino.h>
#include <Framework.h>

class FrameworkArduino: public Framework{

public:
    FrameworkArduino();
    void escribir(int pin, int valor);
    int leer(int pin);
    void demorar(int milisegundos);
    unsigned long microsegundos();
};


#endif //CHIL_FRAMEWORKARDUINO_H
