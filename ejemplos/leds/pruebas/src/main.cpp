#include <PlataformaESP.h>
#include <Chil.h>
#include <pasos.h>

PRUEBAS;

NUEVO_CHIL_CON(PLATAFORMA_ESP);
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

    void presionoElBotonRojo() {
        PLATAFORMA->escribir(BOTON_ROJO, 1);
    }

    void esperoQueEncienda() {
        PLATAFORMA->demorar(25);
    }

    void verificoQueElLedEsteEncendido() {
        verificar(PLATAFORMA->leer(LED_AZUL))->esIgualA(1);
        // Es similar a tener un método boolean con `return PLATAFORMA->leer(LED_AZUL) == 1;`
    }

    void sueltoElBotonRojo() {
        PLATAFORMA->escribir(BOTON_ROJO, 0);
    }

    ESCENARIO(Al presionar por primera vez el boton enciende el led){
        PASO(Cuando presiono el boton, presionoElBotonRojo);
        PASO(Y espero que encienda, esperoQueEncienda);
        PASO(Verifico que el led se enciende, verificoQueElLedEsteEncendido);
        PASO(Suelto el botón, sueltoElBotonRojo);
    };

    FIN_DE_PRUEBAS;

FIN;
