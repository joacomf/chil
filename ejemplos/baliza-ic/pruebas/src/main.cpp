#include <Plataforma.h>
#include <PlataformaArduino.h>
#include <Chil.h>
#include <pasos.h>

PRUEBAS
NUEVO_CHIL_CON(PLATAFORMA_ARDUINO);
PLATAFORMA->demorar(2000);
configurarIO();

    ESCENARIO(Prende indicador de exito al tener una respuesta de build exitoso) {
        PASO(Me conecto a la red WiFi, conectarseARedWifi);
        PASO(Espero a la conexion, esperoALaConexion);
        PASO(El pipeline esta en estado exitoso, elPipelineEstaEnEstadoExitoso);
        PASO(Verifico que se encienda el indicador de exito, indicadorDeExitoEncendido);
    }

    ESCENARIO(Prende indicador de error al tener una respuesta de build fallido) {
        PASO(Me conecto a la red WiFi, sinDefinir);
        PASO(Espero a la conexion, sinDefinir);
        PASO(El pipeline esta en estado fallido, sinDefinir);
        PASO(Verifico que se encienda el indicador de fallo, sinDefinir);
    }

    ESCENARIO(Prende indicador de advertencia al tener un fallo con la conexión a la red) {
        PASO(Me conecto a la red WiFi con credenciales erroneas, sinDefinir);
        PASO(Espero a la conexion, sinDefinir);
        PASO(Verifico que se encienda el indicador de advertencia, sinDefinir);
    }

    ESCENARIO(Prende indicador de advertencia al tener un fallo con la conexión al servidor) {
        PASO(Me conecto a la red WiFi, sinDefinir);
        PASO(Espero a la conexion, sinDefinir);
        PASO(Hay problemas de comunicacion con el servicio, sinDefinir);
        PASO(Verifico que se encienda el indicador de fallo, sinDefinir);
    }

FIN_DE_PRUEBAS;
FIN

