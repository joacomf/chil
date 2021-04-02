#include "../src/FrameworkArduino.cpp"
#include <AUnit.h>

using namespace aunit;

FrameworkArduino *framework;
int led = 2;

void setup() {
  Serial.begin(115200);
}

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
  delay(1);
  assertMore(segundaMedicion, primeraMedicion);
}

test(deberiaObtenerElTiempoUtilizandoMilisegundos) {
  long cero = 0;

  long primeraMedicion = framework->milisegundos();
  delay(10);
  long segundaMedicion = framework->milisegundos();

  assertMore(primeraMedicion, cero);
  assertMore(segundaMedicion, primeraMedicion);
}

void loop() {
  TestRunner::run();
}