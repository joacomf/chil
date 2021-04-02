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

void loop() {
  TestRunner::run();
}