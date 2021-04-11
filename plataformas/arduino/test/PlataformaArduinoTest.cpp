#include "../src/PlataformaArduino.cpp"
#include <AUnit.h>

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
  long cero = 0;

  long primeraMedicion = framework->milisegundos();
  framework->demorar(10);
  long segundaMedicion = framework->milisegundos();

  assertMore(primeraMedicion, cero);
  assertMore(segundaMedicion, primeraMedicion);
}

test(deberiaDemorar100milisegundosEntreLasMediciones) {
  long tiempoDeDemora = 100;

  long primeraMedicion = framework->milisegundos();
  framework->demorar(tiempoDeDemora);
  long segundaMedicion = framework->milisegundos();

  long diferenciaDeTiempo = segundaMedicion - primeraMedicion;

  assertMoreOrEqual(diferenciaDeTiempo, tiempoDeDemora);
}

test(deberiaImprimirPorConsola) {
  framework->consola("Verificacion manual: Deberia imprimir este texto por consola");
}

test(deberiaEstarEncendidaLaRedWiFiAPLuegoDeCrearla) {
  framework->crearRedWiFi("hola", "mundo12345");
  assertTrue(framework->estaWiFiEncendido());
  framework->apagarWiFi();
}

test(deberiaEstarApagadoLaRedWiFIAPSiNuncaSeEncendio) {
  assertFalse(framework->estaWiFiEncendido());
}

void loop() {
  TestRunner::run();
}