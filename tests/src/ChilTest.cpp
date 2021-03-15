#include "Chil.cpp"
#include "gtest/gtest.h"
#include "mocks/MockFramework.h"

MockFramework *framework;

TEST(ChilTest, deberiaCrearseExitosamenteConElFrameworkIndicado) {
  framework = new MockFramework();
  Chil *chil = new Chil(framework);

  ASSERT_EQ(framework, chil->framework);
  delete framework;
}

TEST(ChilTest, deberiaImprimirElResutladoDeDosEscenarioNuevo) {
  framework = new MockFramework();
  Chil *chil = new Chil(framework);

  chil->escenario("Primer escenario sin pasos");
  chil->finalizarEscenario();
  chil->escenario("Segundo escenario sin pasos");
  chil->finalizarEscenario();

  string reporte = chil->imprimir_reporte();

  ASSERT_EQ(reporte, "Escenario: Primer escenario sin pasos\n\n\nEscenario: Segundo escenario sin pasos\n\n\n");
  delete framework;
}