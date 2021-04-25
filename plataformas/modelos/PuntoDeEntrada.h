//
// Created by jmorenof on 18/4/21.
//

#ifndef ARDUINO_PUNTODEENTRADA_H
#define ARDUINO_PUNTODEENTRADA_H
enum Metodo {
    POST,
    GET,
    PUT,
    PATCH
};

class PuntoDeEntrada {
private:
    const char *ruta;
    Metodo metodo;

public:

    explicit PuntoDeEntrada(const char *ruta, Metodo metodo);

    explicit PuntoDeEntrada(const char *ruta);

    const char *obtenerRuta();

    Metodo obtenerMetodo();
};


#endif //ARDUINO_PUNTODEENTRADA_H
