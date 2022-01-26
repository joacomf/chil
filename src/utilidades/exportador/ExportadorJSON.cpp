#include <Chil.h>
#include "ExportadorJSON.h"

string ExportadorJSON::exportarEscenarios() {
    string objetoJSON;
    objetoJSON.append(LLAVE_APERTURA);

    resumen(CHIL->obtener()->obtenerResumen(), objetoJSON);
    objetoJSON.append(COMA);
    escenarios(CHIL->obtener()->obtenerEscenarios(), objetoJSON);

    objetoJSON.append(LLAVE_CIERRE);

    return objetoJSON;
}

void ExportadorJSON::resumen(const Resumen* resumen, string &objetoJSON) {
    objetoJSON.append(COMILLAS).append("resumen").append(COMILLAS)
            .append(DOS_PUNTOS)
            .append(LLAVE_APERTURA);

    objetoJSON.append(dato("completados", resumen->escenarioCompletados())).append(COMA);
    objetoJSON.append(dato("exitosos", resumen->escenariosExitosos())).append(COMA);
    objetoJSON.append(dato("fallidos", resumen->escenarioFallidos()));

    objetoJSON.append(LLAVE_CIERRE);

}

void ExportadorJSON::escenarios(const vector<Escenario*> &escenarios, string &objetoJSON) {
    objetoJSON.append(COMILLAS).append("escenarios").append(COMILLAS)
              .append(DOS_PUNTOS)
              .append(CORCHETE_APERTURA);

    vector<Escenario*>::const_iterator escenarioIterado;
    for(escenarioIterado = escenarios.begin(); escenarioIterado != escenarios.end(); escenarioIterado++) {
        objetoJSON.append(transformar(*escenarioIterado));

        if (next(escenarioIterado) != escenarios.end()) {
            objetoJSON.append(COMA);
        }
    }
    objetoJSON.append(CORCHETE_CIERRE);
}

string ExportadorJSON::transformar(Escenario *escenario) {
    string objetoEscenario;
    objetoEscenario.append(LLAVE_APERTURA)
                   .append(dato("nombre", escenario->nombre)).append(COMA)
                   .append(dato("exitoso", escenario->esExitoso())).append(COMA)

                   .append(COMILLAS).append("pasos").append(COMILLAS)
                   .append(DOS_PUNTOS)
                   .append(CORCHETE_APERTURA);

    transformarPasos(objetoEscenario, escenario->pasos());

    objetoEscenario.append(CORCHETE_CIERRE)
                   .append(LLAVE_CIERRE);

    return objetoEscenario;
}

void ExportadorJSON::transformarPasos(string &objetoEscenario, const vector<Paso *> &pasos) {
    vector<Paso*>::const_iterator pasoIterado;

    for(pasoIterado = pasos.begin(); pasoIterado != pasos.end(); pasoIterado++ ) {
        objetoEscenario.append(transformar(*pasoIterado));
        if (next(pasoIterado) != pasos.end()) {
            objetoEscenario.append(COMA);
        }
    }
}

string ExportadorJSON::transformar(Paso *paso) {
    return string(LLAVE_APERTURA)
            .append(dato("nombre", paso->obtenerNombre())).append(COMA)
            .append(dato("exitoso", paso->esExitoso())).append(COMA)
            .append(dato("tiempo", paso->tiempo())).append(COMA)
            .append(dato("detalleDeError", paso->detalleDeError()))
            .append(LLAVE_CIERRE);
}

string ExportadorJSON::dato(const char *clave, bool valor) {
    string dato;
    dato.append(COMILLAS).append(literales::aTexto(clave)).append(COMILLAS).append(DOS_PUNTOS);
    dato.append(valor ? TEXTO_VERDADERO : TEXTO_FALSO);
    return dato;
}

string ExportadorJSON::dato(const char *clave, const string& valor) {
    string dato;
    dato.append(COMILLAS).append(literales::aTexto(clave)).append(COMILLAS).append(DOS_PUNTOS);
    dato.append(COMILLAS).append(valor).append(COMILLAS);
    return dato;
}

string ExportadorJSON::dato(const char *clave, const char* valor) {
    string dato;
    dato.append(COMILLAS).append(literales::aTexto(clave)).append(COMILLAS).append(DOS_PUNTOS);
    dato.append(COMILLAS).append(valor).append(COMILLAS);
    return dato;
}