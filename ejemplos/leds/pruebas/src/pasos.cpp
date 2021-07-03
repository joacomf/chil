#include "pasos.h"

bool presionoElBoton() {
    PLATAFORMA->escribir(BOTON_ROJO, 1);
    return true;
}

bool sueltoElBoton() {
    PLATAFORMA->escribir(BOTON_ROJO, 0);
    return true;
}

bool elLedEstaEncendido() {
    int estadoLed = PLATAFORMA->leer(LED_AZUL);

    return estadoLed == 1;
}

bool elLedEstaApagado() {
    int estadoLed = PLATAFORMA->leer(LED_AZUL);

    return estadoLed == 0;
}

bool espero25Milis() {
    PLATAFORMA->demorar(25);
    return true;
}

void configurarIO() {
    PLATAFORMA->pinSalida(BOTON_ROJO);
    PLATAFORMA->pinEntrada(LED_AZUL);
}