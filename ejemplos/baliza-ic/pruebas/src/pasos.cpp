#include "pasos.h"

void configurarIO() {
}

bool sinDefinir() {
    return false;
}

bool conectarseARedWifi() {
    return PLATAFORMA->crearRedWiFi("redWifiESP", "400010001");
}

bool esperoALaConexion() {
    PLATAFORMA->demorar(2000);
    return true;
}

bool elPipelineEstaEnEstadoExitoso() {
    PLATAFORMA->crearServidorWeb();
    PLATAFORMA->configurarMockUrls();

    auto* estadoDePipeline = new PuntoDeEntrada(RUTA_ESTADO_PIPELINE);
    estadoDePipeline->configurarRespuesta(RESPUESTA_EXITOSA, "application/json", 200);

    PLATAFORMA->configurarPuntoDeEntrada(estadoDePipeline);

    return true;
}

bool indicadorDeExitoEncendido() {
    unsigned long tiempoInicial = PLATAFORMA->milisegundos();

    while(PLATAFORMA->milisegundos() - tiempoInicial < TIEMPO_LIMITE_VERIFICAR_INDICADOR_MS){
        if (PLATAFORMA->leer(PIN_LED_EXITO) == ESTA_ENCENDIDO) {
            return true;
        }
        PLATAFORMA->demorar(TIEMPO_ENTRE_VERIFICACIONES_INDICADOR);
    }

    return false;
}
