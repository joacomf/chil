#include "pasos.h"

void configurarIO() {
    PLATAFORMA->pinSalida(PIN_DE_REINICIO);
}

bool sinDefinir() {
    return false;
}

bool conectarseARedWifi() {
    return PLATAFORMA->crearRedWiFi("aceptacion", "clave1234");
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

bool reiniciarSUT() {
    PLATAFORMA->escribir(PIN_DE_REINICIO, 0);
    PLATAFORMA->demorar(2);
    PLATAFORMA->escribir(PIN_DE_REINICIO, 1);
    return true;
}

bool elPipelineEstaEnEstadoFallido() {
    auto* estadoDePipeline = new PuntoDeEntrada(RUTA_ESTADO_PIPELINE);
    estadoDePipeline->configurarRespuesta(RESPUESTA_FALLIDA, "application/json", 200);

    PLATAFORMA->configurarPuntoDeEntrada(estadoDePipeline);

    return true;
}

bool indicadorDeFalloEncendido() {
    unsigned long tiempoInicial = PLATAFORMA->milisegundos();

    while(PLATAFORMA->milisegundos() - tiempoInicial < TIEMPO_LIMITE_VERIFICAR_INDICADOR_MS){
        if (PLATAFORMA->leer(PIN_LED_FALLO) == ESTA_ENCENDIDO) {
            return true;
        }
        PLATAFORMA->demorar(TIEMPO_ENTRE_VERIFICACIONES_INDICADOR);
    }

    return false;
}

bool laRedWifiNoExiste() {
    PLATAFORMA->apagarWiFi();
    return true;
}

bool esperoElMaximoDeIntentosDeConexion() {
    PLATAFORMA->demorar(6000);
    return true;
}

bool indicadorDeDesconexionEncendido() {
    unsigned long tiempoInicial = PLATAFORMA->milisegundos();

    while(PLATAFORMA->milisegundos() - tiempoInicial < TIEMPO_LIMITE_VERIFICAR_INDICADOR_MS){
        if (PLATAFORMA->leer(PIN_LED_DESCONEXION) == ESTA_ENCENDIDO) {
            return true;
        }
        PLATAFORMA->demorar(TIEMPO_ENTRE_VERIFICACIONES_INDICADOR);
    }

    return false;
}
