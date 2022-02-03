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
    const char *respuesta{};
    const char *tipo{};
    int codigoDeRespuesta{};

    Metodo metodo;

public:

    explicit PuntoDeEntrada(const char *ruta, Metodo metodo);

    explicit PuntoDeEntrada(const char *ruta);

    const char *obtenerRuta();

    Metodo obtenerMetodo();

    void configurarRespuesta(const char *valor, const char *tipoDeContenido, int codigo);

    const char *obtenerRespuesta();

    const char *obtenerTipo();

    int obtenerCodigoDeRespuesta() const;
};


#endif //ARDUINO_PUNTODEENTRADA_H
