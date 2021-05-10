#include "Chil.cpp"
#include "gtest/gtest.h"
#include "mocks/PlataformaMock.hpp"

using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;
using ::testing::Test;

PlataformaMock *plataforma;

class PruebasDeChil : public Test {
protected:
    void SetUp() override {
        plataforma = new PlataformaMock();
        NUEVO_CHIL_CON(plataforma);
    }

    void TearDown() override {
        delete plataforma;
    }
};

TEST_F(PruebasDeChil, deberiaCrearseExitosamenteConElFrameworkIndicado) {
  ASSERT_EQ(plataforma, CHIL->plataforma);
}

TEST_F(PruebasDeChil, deberiaImprimirElResutladoDeDosEscenarioNuevo) {

  CHIL->escenario("Primer escenario sin pasos");
  CHIL->finalizarEscenario();
  CHIL->escenario("Segundo escenario sin pasos");
  CHIL->finalizarEscenario();

  string reporte = CHIL->imprimirReporte();

  ASSERT_EQ(reporte, "Escenario: Primer escenario sin pasos\n\n\nEscenario: Segundo escenario sin pasos\n\n\n");
}

TEST_F(PruebasDeChil, deberiaEjecutarLaAccionDelPasoDeUnEscenario) {
  EXPECT_CALL(*plataforma, consola(_)).Times(AtLeast(1));
  CHIL->escenario("Primer escenario con dos pasos");

  Paso *dadoQueImprime = new Paso("Imprime hola mundo por consola", []() {
      PLATAFORMA->consola("Hola mundo!");
      return true;
  });

  dadoQueImprime->ejecutar();
}

TEST_F(PruebasDeChil, deberiaEjecutarLaAccionDelPasoDeUnEscenarioConMacro) {
  EXPECT_CALL(*plataforma, consola(_)).Times(AtLeast(2));
  EXPECT_CALL(*plataforma, microsegundos())
          .WillOnce(Return(1L))
          .WillOnce(Return(50L))
          .WillOnce(Return(100L))
          .WillOnce(Return(200L));

  ESCENARIO(Primer escenario con dos pasos) {
    PASO(CHIL, "Imprime por consola el saludo de bienvenida", []() {
        PLATAFORMA->consola("Hola mundo!");
        return true;
    });
    PASO(CHIL, "Imprime por consola el saludo de despedida", []() {
        PLATAFORMA->consola("Adios mundo!");
        return true;
    });
  };
}

TEST_F(PruebasDeChil, deberiaMostrarElResultadoDeTodosLosPasosConSuResultado) {
  EXPECT_CALL(*plataforma, microsegundos())
          .WillOnce(Return(1L))
          .WillOnce(Return(50L))
          .WillOnce(Return(100L))
          .WillOnce(Return(200L));

  EXPECT_CALL(*plataforma, consola(_)).Times(AtLeast(2));

  ESCENARIO(Primer escenario con dos pasos){
      PASO(CHIL, "Imprime por consola el saludo de bienvenida", []() {
          PLATAFORMA->consola("Hola mundo!");
          return true;
      });
      PASO(CHIL, "Imprime por consola el saludo de despedida", []() {
          PLATAFORMA->consola("Adios mundo!");
          return true;
      });
  };

  string reporte = CHIL->imprimirReporte();

  ASSERT_EQ(reporte, "Escenario: Primer escenario con dos pasos\n\n[OK] Imprime por consola el saludo de bienvenida - ejecuto en 49 useg\n[OK] Imprime por consola el saludo de despedida - ejecuto en 100 useg\n\n");
}