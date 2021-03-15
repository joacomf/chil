#include "Chil.cpp"
#include "modelo/Dado.cpp"
#include "gtest/gtest.h"
#include "mocks/MockFramework.hpp"

MockFramework *framework;

using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;


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

  EXPECT_CALL(*framework, consola(_)).Times(AtLeast(1));

  Chil *chil = new Chil(framework);

  chil->escenario("Primer escenario con dos pasos");

  Paso *dadoQueImprime = new Dado("Imprime hola mundo por consola", []() {
      framework->consola("Hola mundo!");
      return true;
  });

  dadoQueImprime->ejecutar();

  delete framework;
}

TEST(ChilTest, deberiaEjecutarLaAccionDelPasoDeUnEscenarioConMacro) {
  framework = new MockFramework();

  EXPECT_CALL(*framework, consola(_)).Times(AtLeast(2));
  EXPECT_CALL(*framework, microsegundos())
          .WillOnce(Return(1L))
          .WillOnce(Return(50L))
          .WillOnce(Return(100L))
          .WillOnce(Return(200L));

  Chil *chil = new Chil(framework);

  ESCENARIO(chil, "Primer escenario con dos pasos", [](Chil *chil){
    PASO(chil, "Imprime por consola el saludo de bienvenida", []() {
        framework->consola("Hola mundo!");
        return true;
    });
    PASO(chil, "Imprime por consola el saludo de despedida", []() {
        framework->consola("Adios mundo!");
        return true;
    });
  });

  delete framework;
}

TEST(ChilTest, deberiaMostrarElResultadoDeTodosLosPasosConSuResultado) {
  framework = new MockFramework();

  EXPECT_CALL(*framework, microsegundos())
          .WillOnce(Return(1L))
          .WillOnce(Return(50L))
          .WillOnce(Return(100L))
          .WillOnce(Return(200L));

  Chil *chil = new Chil(framework);

  EXPECT_CALL(*framework, consola(_)).Times(AtLeast(2));

  ESCENARIO(chil, "Primer escenario con dos pasos", [](Chil *chil){
      PASO(chil, "Imprime por consola el saludo de bienvenida", []() {
          framework->consola("Hola mundo!");
          return true;
      });
      PASO(chil, "Imprime por consola el saludo de despedida", []() {
          framework->consola("Adios mundo!");
          return true;
      });
  });

  string reporte = chil->imprimir_reporte();

  ASSERT_EQ(reporte, "Escenario: Primer escenario con dos pasos\n\n[OK] Imprime por consola el saludo de bienvenida - ejecuto en 49 useg\n[OK] Imprime por consola el saludo de despedida - ejecuto en 100 useg\n\n");

  delete framework;
}