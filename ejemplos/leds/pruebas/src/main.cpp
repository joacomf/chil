#include <Arduino.h>
#include <Chil.h>
#include <Plataforma.h>
#include <PlataformaArduino.h>

#define BOTON_ROJO 4
#define LED_AZUL 2

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

void setup() {
    NUEVO_CHIL_CON(new PlataformaArduino());
    PLATAFORMA->demorar(1000);

    configurarIO();

    ESCENARIO(Al presionar por primera vez el boton enciende el led){
        PASO(Cuando presiono el boton, presionoElBoton);
        PASO(Y espero que encienda, espero25Milis);
        PASO(Verifico que el led se enciende, elLedEstaEncendido);
        PASO(Suelto el boton, sueltoElBoton);
    };

    ESCENARIO(Al soltar luego de estar presionado se apaga el led){
        PASO(Dado que presiono el boton, presionoElBoton);
        PASO(Y espero que encienda, espero25Milis);
        PASO(Cuando suelto el boton, sueltoElBoton);
        PASO(Y espero que apague, espero25Milis);
        PASO(Verifico que el led se apaga, elLedEstaApagado);
    };

    PLATAFORMA->consola(CHIL->imprimirReporte().c_str());
}

void loop() {
}