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
    const char *respuesta;
    const char *tipo;

    Metodo metodo;

public:

    explicit PuntoDeEntrada(const char *ruta, Metodo metodo);

    explicit PuntoDeEntrada(const char *ruta);

    const char *obtenerRuta();

    Metodo obtenerMetodo();

    void configurarRespuesta(const char *valor, const char *tipo);

    const char *obtenerRespuesta();

    const char *obtenerTipo();
};


#endif //ARDUINO_PUNTODEENTRADA_H
