#ifndef CHIL_EXPORTADORJSON_H
#define CHIL_EXPORTADORJSON_H

#include <vector>
#include <string>

#include <modelo/Escenario.h>
#include <modelo/Resumen.h>

using std::vector;
using std::string;

class ExportadorJSON {

public:
    static string generar();

private:
    constexpr static const char *const COMILLAS = "\"";
    constexpr static const char *const DOS_PUNTOS = ":";
    constexpr static const char *const COMA = ",";
    constexpr static const char *const LLAVE_APERTURA = "{";
    constexpr static const char *const LLAVE_CIERRE = "}";
    constexpr static const char *const CORCHETE_APERTURA = "[";
    constexpr static const char *const CORCHETE_CIERRE = "]";
    constexpr static const char *const TEXTO_VERDADERO = "true";
    constexpr static const char *const TEXTO_FALSO = "false";

    static string transformar(Escenario* escenario);
    static string transformar(Paso* paso);

    static string dato(const char *clave, bool valor);
    static string dato(const char *clave, const string& valor);
    static string dato(const char *clave, const char *valor);

    template<typename T>
    static string dato(const char *clave, T valor){
        string dato;
        dato.append(COMILLAS).append(literales::aTexto(clave)).append(COMILLAS).append(DOS_PUNTOS);
        dato.append(literales::aTexto(valor));
        return dato;
    }

    static void transformarPasos(string &objetoEscenario, const vector<Paso *> &pasos);

    static void escenarios(const vector<Escenario *> &escenarios, string &objetoJSON);
    static void resumen(const Resumen* resumen, string &objetoJSON);
};


#endif //CHIL_EXPORTADORJSON_H
