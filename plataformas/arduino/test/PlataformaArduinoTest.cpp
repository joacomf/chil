#include "../src/PlataformaArduino.cpp"
#include <AUnit.h>
#include "../../modelos/PuntoDeEntrada.cpp"

using namespace aunit;

PlataformaArduino *framework = new PlataformaArduino();
int led = 2;

void setup() {}

test(deberiaEncenderElLedIndicado) {
  framework->pinSalida(led);
  framework->escribir(led, HIGH);

  assertEqual(framework->leer(led), HIGH);
}

test(deberiaObtenerElTiempoEnMicrosegundos) {
  unsigned long cero = 0;

  unsigned long primeraMedicion = framework->microsegundos();
  unsigned long segundaMedicion = framework->microsegundos();

  assertMore(primeraMedicion, cero);
  framework->demorar(1);
  assertMoreOrEqual(segundaMedicion, primeraMedicion);
}

test(deberiaObtenerElTiempoUtilizandoMilisegundos) {
  unsigned long cero = 0;

  unsigned long primeraMedicion = framework->milisegundos();
  framework->demorar(10);
  unsigned long segundaMedicion = framework->milisegundos();

  assertMore(primeraMedicion, cero);
  assertMore(segundaMedicion, primeraMedicion);
}

test(deberiaDemorar100milisegundosEntreLasMediciones) {
  long tiempoDeDemora = 100;

  unsigned long primeraMedicion = framework->milisegundos();
  framework->demorar(tiempoDeDemora);
  unsigned long segundaMedicion = framework->milisegundos();

  unsigned long diferenciaDeTiempo = segundaMedicion - primeraMedicion;

  assertMoreOrEqual(diferenciaDeTiempo, (unsigned long) tiempoDeDemora);
}

test(deberiaImprimirPorConsola) {
  framework->consola("Verificacion manual: Deberia imprimir este texto por consola");
}

test(deberiaEstarEncendidaLaRedWiFiAPLuegoDeCrearla) {
  framework->crearRedWiFi("hola", "mundo12345");
  assertTrue(framework->estaAPEncendido());
  framework->apagarWiFi();
}

test(aaDeberiaEstarApagadoLaRedWiFIAPSiNuncaSeEncendio) {
  framework->apagarWiFi();
  framework->demorar(400);

  assertFalse(framework->estaAPEncendido());
}

test(aDeberiaNoTenerServidorWebCreadoPorDefault) {
    assertFalse(framework->estaServidorCorriendo());
}

test(aDeberiaCrearUnServidorWeb) {
    framework->crearRedWiFi("servidor", "http12345");
    framework->crearServidorWeb();

    assertTrue(framework->estaServidorCorriendo());

    framework->eliminarServidorWeb();
}

test(aDeberiaEliminarServidorWebLuegoDeEncenderlo) {
    framework->crearRedWiFi("servidor", "http12345");
    framework->crearServidorWeb();
    framework->eliminarServidorWeb();

    assertFalse(framework->estaServidorCorriendo());
}


test(deberiaCrearUnPuntoDeEntradaDePingAlCrearElServidorWeb) {
  framework->crearRedWiFi("servidor", "http12345");
  framework->crearServidorWeb();

  HTTPClient cliente;
  cliente.begin("http://" + WiFi.softAPIP().toString() + "/chil-ping");

  int codigoDeRespuesta = cliente.GET();
  String respuesta = cliente.getString();
  cliente.end();

  assertEqual(200, codigoDeRespuesta);
  assertEqual("chil-pong", respuesta);

  framework->apagarWiFi();
  framework->eliminarServidorWeb();
}

test(deberiaAgregarPuntoDeEntradaAlServidorCreado) {

  auto* puntoDeEntrada = new PuntoDeEntrada("/numeros");
  puntoDeEntrada->configurarRespuesta("numeros", "text/plain");

  framework->crearRedWiFi("servidor", "http12345");
  framework->crearServidorWeb();
  framework->configurarPuntoDeEntrada(puntoDeEntrada);

  HTTPClient cliente;
  String urlAConsultar = "http://" + WiFi.softAPIP().toString() + "/numeros";
  cliente.begin(urlAConsultar);

  int codigoDeRespuesta = cliente.GET();
  String respuesta = cliente.getString();
  cliente.end();

  assertEqual(200, codigoDeRespuesta);
  assertEqual("numeros", respuesta);

  framework->apagarWiFi();
  framework->eliminarServidorWeb();
}

test(deberiaAgregarPuntoDeEntradaParaMetodoPostAlServidorCreado) {
    auto* puntoDeEntrada = new PuntoDeEntrada("/ping", POST);

    framework->crearRedWiFi("servidor", "http12345");
    framework->crearServidorWeb();
    framework->configurarPuntoDeEntrada(puntoDeEntrada);
    framework->demorar(200);

    HTTPClient cliente;
    String urlAConsultar = "http://" + WiFi.softAPIP().toString() + "/ping";
    cliente.begin(urlAConsultar);

    int codigoDeRespuesta = cliente.POST("");
    cliente.end();

    assertEqual(200, codigoDeRespuesta);

    framework->apagarWiFi();
    framework->eliminarServidorWeb();
}

void loop() {
  TestRunner::run();
}