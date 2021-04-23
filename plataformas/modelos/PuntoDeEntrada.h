//
// Created by jmorenof on 18/4/21.
//

#ifndef ARDUINO_PUNTODEENTRADA_H
#define ARDUINO_PUNTODEENTRADA_H


class PuntoDeEntrada {
private:
    const char *ruta;

public:
    explicit PuntoDeEntrada(const char *ruta);

    const char *obtenerRuta();
};


#endif //ARDUINO_PUNTODEENTRADA_H
