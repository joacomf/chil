#ifndef CHIL_FRAMEWORKARDUINO_H
#define CHIL_FRAMEWORKARDUINO_H

#include <Arduino.h>

class FrameworkArduino{
private:
    int velocidadSerial = 115200;

public:
    FrameworkArduino();
    void escribir(int pin, int valor);
    int leer(int pin);
    void demorar(int milisegundos);
    unsigned long milisegundos();
    unsigned long microsegundos();
    void pinSalida(int pin);
};


#endif //CHIL_FRAMEWORKARDUINO_H
