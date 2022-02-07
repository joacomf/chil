#ifndef PRUEBAS_PASOS_H
#define PRUEBAS_PASOS_H

#include <stdexcept>

using namespace std;

#include <Chil.h>
#include <modelo/verificacion/Verificacion.h>
#include "respuestas.h"

#define PRUEBAS void setup() {
#define FIN } void loop() {}

#define PIN_LED_EXITO 2
#define PIN_LED_FALLO 4
#define PIN_DE_REINICIO 19
#define PIN_LED_DESCONEXION 21

#define ESTA_ENCENDIDO 1
#define RUTA_ESTADO_PIPELINE "/repo/20183492/branch/master"
#define TIEMPO_LIMITE_VERIFICAR_INDICADOR_MS 4000
#define TIEMPO_ENTRE_VERIFICACIONES_INDICADOR 20

void sinDefinir();
void configurarIO();
bool conectarseARedWifi();
void esperoALaConexion();
void elPipelineEstaEnEstadoExitoso();
bool queElIndicadorDeExitoEncendido();
void indicadorDeExitoEncendido();
void reiniciarSUT();
void elPipelineEstaEnEstadoFallido();
void indicadorDeFalloEncendido();
void laRedWifiNoExiste();
void esperoElMaximoDeIntentosDeConexion();
void indicadorDeDesconexionEncendido();
void hayProblemasDeComunicacionConElServicio();

#endif //PRUEBAS_PASOS_H
