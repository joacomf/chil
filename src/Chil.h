#ifndef CHIL_CHIL_H
#define CHIL_CHIL_H

#include "interfaces/Plataforma.h"
#include "modelo/Escenario.h"
#include "modelo/Resumen.h"
#include "macros.h"
#include "utilidades/exportador/ExportadorJSON.h"

#include <vector>
#include <string>

#define NUEVO_CHIL_CON(plataforma) Chil::crear(plataforma)
#define FIN_DE_PRUEBAS Chil::obtener()->finalizarPruebas()
#define CHIL Chil::obtener()
#define PLATAFORMA Chil::obtener()->plataforma
#define EXPORTAR_JSON Chil::obtener()->exportarJSON()

#define PRUEBAS void setup() {
#define FIN } void loop() {}

using namespace std;

class Chil {

protected:
    explicit Chil(Plataforma *pPlataforma);
    ~Chil() = default;

public:
    Chil(Chil &other) = delete;
    void operator=(const Chil &) = delete;

    static Chil* crear(Plataforma *plataforma);
    static Chil *obtener();

    Plataforma* plataforma;

    string imprimirReporte();
    void escenario(const char *nombre);

    void finalizarEscenario();
    void finalizarPruebas();

    void paso(Paso *paso);

    string imprimirResumen();

    const vector<Escenario *> &obtenerEscenarios();

    Resumen *obtenerResumen();
    void exportarJSON();

private:
    constexpr static const char *const ETIQUETA_COMIENZO_JSON = "COMIENZO_JSON";
    constexpr static const char *const ETIQUETA_FIN_JSON = "FIN_JSON";

    Escenario *_escenario{};
    vector<Escenario*> _escenarios;
    const char *mensajeComienzo = "\nPruebas con CHIL:\n";
    const char *mensajeFinDePruebas = "Fin de pruebas con CHIL";
    Resumen *resumen;
};

#endif //CHIL_CHIL_H
