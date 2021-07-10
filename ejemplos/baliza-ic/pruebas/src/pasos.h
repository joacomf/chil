#ifndef PRUEBAS_PASOS_H
#define PRUEBAS_PASOS_H

#include <Chil.h>

#define PRUEBAS void setup() {
#define FIN } void loop() {}

#define PIN_LED_EXITO 2
#define RUTA_ESTADO_PIPELINE "/repo/20183492/branch/master"
#define ESTA_ENCENDIDO 1
#define TIEMPO_LIMITE_VERIFICAR_INDICADOR_MS 20000
#define TIEMPO_ENTRE_VERIFICACIONES_INDICADOR 200

static const char *const RESPUESTA_EXITOSA = R"({
   "@type":"branch",
   "@href":"/repo/6350830/branch/master",
   "@representation":"standard",
   "name":"master",
   "repository":{
      "@type":"repository",
      "@href":"/repo/6350830",
      "@representation":"minimal",
      "id":6350830,
      "name":"dyasc-baliza-ic",
      "slug":"joacomf/dyasc-baliza-ic"
   },
   "default_branch":true,
   "exists_on_github":true,
   "last_build":{
      "@type":"build",
      "@href":"/build/88533221",
      "@representation":"minimal",
      "id":88533221,
      "number":"59",
      "state":"passed",
      "duration":51,
      "event_type":"push",
      "previous_state":"passed",
      "pull_request_title":null,
      "pull_request_number":null,
      "started_at":"2018-10-19T12:00:09Z",
      "finished_at":"2018-10-19T12:01:00Z",
      "private":false,
      "priority":false
   }
})";

void configurarIO();
bool sinDefinir();
bool conectarseARedWifi();
bool esperoALaConexion();
bool elPipelineEstaEnEstadoExitoso();
bool indicadorDeExitoEncendido();

#endif //PRUEBAS_PASOS_H
