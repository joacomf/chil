#include "gtest/gtest.h"
#include "modelo/Escenario.cpp"


TEST(Escenario, alGenerarReporteNoTieneNingunResultado) {
  auto* escenario = new Escenario("Escenario nulo");
  string resultado = escenario->imprimirResultado();

  ASSERT_EQ(resultado, "Escenario: Escenario nulo\n\n");
}