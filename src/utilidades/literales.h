#ifndef CHIL_LITERALES_H
#define CHIL_LITERALES_H

#include <string>
#include <sstream>

using std::string;

/**
 * Namespace para emparchar el soporte de to_string de std::string
 */
namespace patch
{
    /**
     * Metodo para generar un literal (string) de un valor
     * soportado por los compiladores de los microcontroladores
     *
     * @param const T& texto - valor a convertir
     * @return [out][std::string] valor convertido a string.
     */
    template < typename T >
    string to_string( const T& texto ){
        std::ostringstream stream;
        stream << texto;
        return stream.str();
    }
}

namespace literales {
    template<typename T>
    string aTexto(const T &t) {
        return patch::to_string(t);
    }

    string aTexto(const char* t);
    string aTexto(const string& t);

    template <typename ...Args>
    std::string formato(const std::string& textoPlantilla, Args && ...argumentos)
    {
        int espacio = std::snprintf(nullptr, 0, textoPlantilla.c_str(), std::forward<Args>(argumentos)...);
        std::string salida(espacio, '\0');
        std::sprintf(&salida[0], textoPlantilla.c_str(), std::forward<Args>(argumentos)...);
        return salida;
    }
}

#endif //CHIL_LITERALES_H
