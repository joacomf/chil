#include <Plataforma.h>
#include <PlataformaArduino.h>
#include <Chil.h>
#include <pasos.h>

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

void loop() {}