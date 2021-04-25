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

class ServidorWebTest: public TestOnce {
protected:
    void setup() override {
        TestOnce::setup();
        framework->crearRedWiFi("servidor", "http12345");
        framework->crearServidorWeb();
        framework->demorar(100);
    }

    void teardown() override {
        framework->apagarWiFi();
        framework->eliminarServidorWeb();
        TestOnce::teardown();
    }
};



testF(ServidorWebTest, aDeberiaCrearUnServidorWeb) {
    assertTrue(framework->estaServidorCorriendo());
}

testF(ServidorWebTest, aDeberiaEliminarServidorWebLuegoDeEncenderlo) {
    framework->eliminarServidorWeb();

    assertFalse(framework->estaServidorCorriendo());
}


testF(ServidorWebTest, deberiaCrearUnPuntoDeEntradaDePingAlCrearElServidorWeb) {
  HTTPClient cliente;
  cliente.begin("http://" + WiFi.softAPIP().toString() + "/chil-ping");

  int codigoDeRespuesta = cliente.GET();
  String respuesta = cliente.getString();
  cliente.end();

  assertEqual(200, codigoDeRespuesta);
  assertEqual("chil-pong", respuesta);
}

testF(ServidorWebTest, deberiaAgregarPuntoDeEntradaAlServidorCreado) {
  auto* puntoDeEntrada = new PuntoDeEntrada("/numeros");
  puntoDeEntrada->configurarRespuesta("numeros", "text/plain");

  framework->configurarPuntoDeEntrada(puntoDeEntrada);

  HTTPClient cliente;
  String urlAConsultar = "http://" + WiFi.softAPIP().toString() + "/numeros";
  cliente.begin(urlAConsultar);

  int codigoDeRespuesta = cliente.GET();
  String respuesta = cliente.getString();
  cliente.end();

  assertEqual(200, codigoDeRespuesta);
  assertEqual("numeros", respuesta);
}

testF(ServidorWebTest, deberiaAgregarPuntoDeEntradaParaMetodoPostAlServidorCreado) {
    auto* puntoDeEntrada = new PuntoDeEntrada("/ping", POST);

    framework->configurarPuntoDeEntrada(puntoDeEntrada);
    framework->demorar(200);

    HTTPClient cliente;
    String urlAConsultar = "http://" + WiFi.softAPIP().toString() + "/ping";
    cliente.begin(urlAConsultar);

    int codigoDeRespuesta = cliente.POST("");
    cliente.end();

    assertEqual(200, codigoDeRespuesta);
}

void loop() {
  TestRunner::run();
}