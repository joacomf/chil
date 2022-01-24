
#ifndef CHIL_VALORESMAYOREXCEPTION_H
#define CHIL_VALORESMAYOREXCEPTION_H

using std::exception;
using std::string;
using literales::aTexto;

template <typename T>
class ValorEsMayorExcepcion : public exception {

private:
    constexpr static const char *const TEXTO_ESPERADO = "Se esperaba el valor: ";
    constexpr static const char *const TEXTO_RECIBIDO = "Sea menor a: ";
    constexpr static const char *const TEXTO_FINAL = "Pero no lo es";
    constexpr static const char *const SALTO_DE_LINEA = "\n";

    string mensaje{};

public:
    explicit ValorEsMayorExcepcion(T recibido, T esperado) {
        mensaje.append(TEXTO_ESPERADO).append(SALTO_DE_LINEA);
        mensaje.append(aTexto(esperado)).append(SALTO_DE_LINEA);
        mensaje.append(TEXTO_RECIBIDO).append(SALTO_DE_LINEA);
        mensaje.append(aTexto(recibido)).append(SALTO_DE_LINEA);
        mensaje.append(TEXTO_FINAL).append(SALTO_DE_LINEA);
    }

    string obtenerMensaje() {
        return mensaje;
    }
};
#endif //CHIL_VALORESMAYOREXCEPTION_H
