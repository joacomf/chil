#ifndef CHIL_PLATAFORMA_H
#define CHIL_PLATAFORMA_H

class Plataforma {

public:
    virtual void consola(const char *nombre) = 0;
    virtual void escribir(int pin, int valor) = 0;
    virtual int leer(int pin) = 0;
    virtual void demorar(int milisegundos) = 0;
    virtual unsigned long milisegundos() = 0;
    virtual unsigned long microsegundos() = 0;
    virtual void pinSalida(int pin) = 0;
    virtual bool crearRedWiFi(const char *nombre, const char *clave) = 0;
};


#endif //CHIL_PLATAFORMA_H
