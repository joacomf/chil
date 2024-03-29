#include <PlataformaESP.h>
#include <Chil.h>
#include <pasos.h>

PRUEBAS
NUEVO_CHIL_CON(PLATAFORMA_ESP);
PLATAFORMA->demorar(2000);
configurarIO();

    ESCENARIO(Prende indicador de advertencia al tener un fallo con la conexión a la red) {
        PASO(La red wifi no existe, laRedWifiNoExiste);
        PASO(Reiniciar dispositivo, reiniciarSUT);
        PASO(Espero al maximo de intentos de conexion, esperoElMaximoDeIntentosDeConexion);
        PASO(Verifico que se encienda el indicador de advertencia, indicadorDeDesconexionEncendido);
    }

    ESCENARIO(Prende indicador de exito al tener una respuesta de build exitoso) {
        PASO(Me conecto a la red WiFi, conectarseARedWifi);
        PASO(Reiniciar dispositivo, reiniciarSUT);
        PASO(El pipeline esta en estado exitoso, elPipelineEstaEnEstadoExitoso);
        PASO(Espero a la conexion, esperoALaConexion);
        PASO(Verifico que se encienda el indicador de exito, indicadorDeExitoEncendido);
    }

    ESCENARIO(Prende indicador de error al tener una respuesta de build fallido) {
        PASO(Reiniciar dispositivo, reiniciarSUT);
        PASO(El pipeline esta en estado fallido, elPipelineEstaEnEstadoFallido);
        PASO(Espero a la conexion, esperoALaConexion);
        PASO(Verifico que se encienda el indicador de fallo, indicadorDeFalloEncendido);
    }

    ESCENARIO(Prende indicador de advertencia al tener un fallo con la conexión al servidor) {
        PASO(Reiniciar dispositivo, reiniciarSUT);
        PASO(Hay problemas de comunicacion con el servicio, hayProblemasDeComunicacionConElServicio);
        PASO(Espero a la conexion, esperoALaConexion);
        PASO(Verifico que se encienda el indicador de advertencia, indicadorDeDesconexionEncendido);
    }

FIN_DE_PRUEBAS;
FIN

