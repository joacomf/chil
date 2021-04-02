#ifndef CHIL_FRAMEWORKARDUINO_H
#define CHIL_FRAMEWORKARDUINO_H

#include <Arduino.h>

class FrameworkArduino{

public:
    FrameworkArduino();
    void escribir(int pin, int valor);
    int leer(int pin);
    void demorar(int milisegundos);
    unsigned long microsegundos();
    void pinSalida(int pin);
};


#endif //CHIL_FRAMEWORKARDUINO_H
