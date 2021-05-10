#include "Chil.cpp"
#include "gtest/gtest.h"
#include "mocks/MockFramework.hpp"

using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;
using ::testing::Test;

MockFramework *framework;

class PruebasDeChil : public Test {
protected:
    void SetUp() override {
        framework = new MockFramework();
        Chil::crear(framework);
    }

    void TearDown() override {
        delete framework;
    }
};

TEST_F(PruebasDeChil, deberiaCrearseExitosamenteConElFrameworkIndicado) {
  ASSERT_EQ(framework, Chil::obtener()->framework);
}

TEST_F(PruebasDeChil, deberiaImprimirElResutladoDeDosEscenarioNuevo) {

  Chil::obtener()->escenario("Primer escenario sin pasos");
  Chil::obtener()->finalizarEscenario();
  Chil::obtener()->escenario("Segundo escenario sin pasos");
  Chil::obtener()->finalizarEscenario();

  string reporte = Chil::obtener()->imprimir_reporte();

  ASSERT_EQ(reporte, "Escenario: Primer escenario sin pasos\n\n\nEscenario: Segundo escenario sin pasos\n\n\n");
}

TEST_F(PruebasDeChil, deberiaEjecutarLaAccionDelPasoDeUnEscenario) {
  EXPECT_CALL(*framework, consola(_)).Times(AtLeast(1));
  Chil::obtener()->escenario("Primer escenario con dos pasos");

  Paso *dadoQueImprime = new Paso("Imprime hola mundo por consola", []() {
      framework->consola("Hola mundo!");
      return true;
  });

  dadoQueImprime->ejecutar();
}

TEST_F(PruebasDeChil, deberiaEjecutarLaAccionDelPasoDeUnEscenarioConMacro) {
  EXPECT_CALL(*framework, consola(_)).Times(AtLeast(2));
  EXPECT_CALL(*framework, microsegundos())
          .WillOnce(Return(1L))
          .WillOnce(Return(50L))
          .WillOnce(Return(100L))
          .WillOnce(Return(200L));

  ESCENARIO(Chil::obtener(), "Primer escenario con dos pasos", [](Chil *chil){
    PASO(Chil::obtener(), "Imprime por consola el saludo de bienvenida", []() {
        framework->consola("Hola mundo!");
        return true;
    });
    PASO(chil, "Imprime por consola el saludo de despedida", []() {
        framework->consola("Adios mundo!");
        return true;
    });
  });
}

TEST_F(PruebasDeChil, deberiaMostrarElResultadoDeTodosLosPasosConSuResultado) {
  EXPECT_CALL(*framework, microsegundos())
          .WillOnce(Return(1L))
          .WillOnce(Return(50L))
          .WillOnce(Return(100L))
          .WillOnce(Return(200L));

  EXPECT_CALL(*framework, consola(_)).Times(AtLeast(2));

  ESCENARIO(Chil::obtener(), "Primer escenario con dos pasos", [](Chil *chil){
      PASO(Chil::obtener(), "Imprime por consola el saludo de bienvenida", []() {
          framework->consola("Hola mundo!");
          return true;
      });
      PASO(chil, "Imprime por consola el saludo de despedida", []() {
          framework->consola("Adios mundo!");
          return true;
      });
  });

  string reporte = Chil::obtener()->imprimir_reporte();

  ASSERT_EQ(reporte, "Escenario: Primer escenario con dos pasos\n\n[OK] Imprime por consola el saludo de bienvenida - ejecuto en 49 useg\n[OK] Imprime por consola el saludo de despedida - ejecuto en 100 useg\n\n");
}