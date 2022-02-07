#include "pasos.h"

void configurarIO() {
    PLATAFORMA->pinSalida(PIN_DE_REINICIO);
}

void sinDefinir() {
    throw invalid_argument("Paso sin definir");
}

bool conectarseARedWifi() {
    return PLATAFORMA->crearRedWiFi("aceptacion", "clave1234");
}

void esperoALaConexion() {
    PLATAFORMA->demorar(2000);
}

void elPipelineEstaEnEstadoExitoso() {
    PLATAFORMA->crearServidorWeb();
    PLATAFORMA->configurarMockUrls();

    auto* estadoDePipeline = new PuntoDeEntrada(RUTA_ESTADO_PIPELINE);
    estadoDePipeline->configurarRespuesta(RESPUESTA_EXITOSA, "application/json", 200);

    PLATAFORMA->configurarPuntoDeEntrada(estadoDePipeline);
}

bool queElIndicadorDeExitoEncendido() {
    return PLATAFORMA->leer(PIN_LED_EXITO) == ESTA_ENCENDIDO;
}

void indicadorDeExitoEncendido() {
    comprobar(queElIndicadorDeExitoEncendido)
                        ->durante(TIEMPO_LIMITE_VERIFICAR_INDICADOR_MS)
                        ->conIntervaloDe(TIEMPO_ENTRE_VERIFICACIONES_INDICADOR)
                        ->seHayaEjecutado();
}

void reiniciarSUT() {
    PLATAFORMA->escribir(PIN_DE_REINICIO, 0);
    PLATAFORMA->demorar(2);
    PLATAFORMA->escribir(PIN_DE_REINICIO, 1);
}

void elPipelineEstaEnEstadoFallido() {
    auto* estadoDePipeline = new PuntoDeEntrada(RUTA_ESTADO_PIPELINE);
    estadoDePipeline->configurarRespuesta(RESPUESTA_FALLIDA, "application/json", 200);

    PLATAFORMA->configurarPuntoDeEntrada(estadoDePipeline);
}

void indicadorDeFalloEncendido() {
    comprobar([](){ 
            return PLATAFORMA->leer(PIN_LED_FALLO) == ESTA_ENCENDIDO;
        })
        ->durante(TIEMPO_LIMITE_VERIFICAR_INDICADOR_MS)
        ->conIntervaloDe(TIEMPO_ENTRE_VERIFICACIONES_INDICADOR)
        ->seHayaEjecutado();
}

void laRedWifiNoExiste() {}

void esperoElMaximoDeIntentosDeConexion() {
    PLATAFORMA->demorar(4000);
}

void indicadorDeDesconexionEncendido() {
    comprobar([](){ 
        return PLATAFORMA->leer(PIN_LED_DESCONEXION) == ESTA_ENCENDIDO;
    })
    ->durante(TIEMPO_LIMITE_VERIFICAR_INDICADOR_MS)
    ->conIntervaloDe(TIEMPO_ENTRE_VERIFICACIONES_INDICADOR)
    ->seHayaEjecutado();
}

void hayProblemasDeComunicacionConElServicio() {
    auto* estadoDePipeline = new PuntoDeEntrada(RUTA_ESTADO_PIPELINE);
    estadoDePipeline->configurarRespuesta(RESPUESTA_VACIA, "application/json", 500);

    PLATAFORMA->configurarPuntoDeEntrada(estadoDePipeline);
}
