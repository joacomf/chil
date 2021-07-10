#ifndef PRUEBAS_PASOS_H
#define PRUEBAS_PASOS_H

#include <Chil.h>
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

void configurarIO();
bool conectarseARedWifi();
bool esperoALaConexion();
bool elPipelineEstaEnEstadoExitoso();
bool indicadorDeExitoEncendido();
bool reiniciarSUT();
bool elPipelineEstaEnEstadoFallido();
bool indicadorDeFalloEncendido();
bool laRedWifiNoExiste();
bool esperoElMaximoDeIntentosDeConexion();
bool indicadorDeDesconexionEncendido();
bool hayProblemasDeComunicacionConElServicio();

#endif //PRUEBAS_PASOS_H
