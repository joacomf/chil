#include "Chil.cpp"
#include "modelo/Dado.cpp"
#include "gtest/gtest.h"
#include "mocks/MockFramework.hpp"

MockFramework* framework;

using ::testing::AtLeast;
using ::testing::_;

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

TEST(ChilTest, deberiaEjecutarLaAccionDelPasoDeUnEscenario) {
  framework = new MockFramework();
  Chil *chil = new Chil(framework);

  EXPECT_CALL(*framework, consola(_)).Times(AtLeast(1));

  chil->escenario("Primer escenario con dos pasos");

  Paso *imprimePorConsola = new Dado("Imprime hola mundo por consola", []() {
      framework->consola("Hola mundo!");
  });

  chil->paso(imprimePorConsola);
  chil->finalizarEscenario();

  string reporte = chil->imprimir_reporte();

  delete framework;
}

TEST(ChilTest, deberiaEjecutarLaAccionDelPasoDeUnEscenarioConMacro) {
  framework = new MockFramework();
  Chil *chil = new Chil(framework);

  EXPECT_CALL(*framework, consola(_)).Times(AtLeast(2));

  ESCENARIO(chil, "Primer escenario con dos pasos", [](Chil *chil){
    PASO(chil, "Imprime por consola el saludo de bienvenida", []() {
        framework->consola("Hola mundo!");
    });
    PASO(chil, "Imprime por consola el saludo de despedida", []() {
        framework->consola("Adios mundo!");
    });
  });

  delete framework;
}