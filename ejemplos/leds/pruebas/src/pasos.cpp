#include "pasos.h"
#include "modelo/verificacion/Verificacion.h"


void presionoElBoton() {
    PLATAFORMA->escribir(BOTON_ROJO, 1);
}

void sueltoElBoton() {
    PLATAFORMA->escribir(BOTON_ROJO, 0);
}

void elLedEstaEncendido() {
    verificar(PLATAFORMA->leer(LED_AZUL))->esIgualA(1);
}

void elLedEstaApagado() {
    verificar(PLATAFORMA->leer(LED_AZUL))->esIgualA(0);
}

void espero25Milis() {
    PLATAFORMA->demorar(25);
}

void configurarIO() {
    PLATAFORMA->pinSalida(BOTON_ROJO);
    PLATAFORMA->pinEntrada(LED_AZUL);
}