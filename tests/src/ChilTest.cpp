#include "compartido-tests.h"

TEST(PruebasDeChilInicilizacion, alCrearChilDeberiaImprimirElMensajeDeComienzo) {
    auto *plataforma = new PlataformaMock();
    EXPECT_CALL(*plataforma, consola(StrEq("\nPruebas con CHIL:\n"))).Times(Exactly(1));
    NUEVO_CHIL_CON(plataforma);

    delete plataforma;
}

TEST(PruebasDeChilFinalizacion, alFinalizarChilDeberiaImprimirElMensajeDeFinalizacion) {
    auto *plataforma = new PlataformaMock();
    EXPECT_CALL(*plataforma, consola(_)).WillOnce(Return());
    NUEVO_CHIL_CON(plataforma);

    EXPECT_CALL(*plataforma, consola(_)).Times(AtLeast(1));
    EXPECT_CALL(*plataforma, consola(StrEq("Fin de pruebas con CHIL"))).Times(AtLeast(1));
    FIN_DE_PRUEBAS;

    delete plataforma;
}
PlataformaMock *plataforma;

class PruebasDeChil : public Test {
protected:
    void SetUp() override {
        plataforma = new PlataformaMock();
        EXPECT_CALL(*plataforma, consola(_)).WillRepeatedly(Return());
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
    PASO(Imprime por consola el saludo de bienvenida, []() {
        PLATAFORMA->consola("Hola mundo!");
        return true;
    });
    PASO(Imprime por consola el saludo de despedida, []() {
        PLATAFORMA->consola("Adios mundo!");
        return true;
    });
  };
}

TEST_F(PruebasDeChil, deberiaMostrarElResultadoDeTodosLosPasosUtilizandoLambdasConSuResultado) {
  EXPECT_CALL(*plataforma, microsegundos())
          .WillOnce(Return(1L))
          .WillOnce(Return(50L))
          .WillOnce(Return(100L))
          .WillOnce(Return(200L));

  EXPECT_CALL(*plataforma, consola(_)).Times(AtLeast(2));

  ESCENARIO(Primer escenario con dos pasos){
      PASO(Imprime por consola el saludo de bienvenida, []() {
          PLATAFORMA->consola("Hola mundo!");
          return true;
      });
      PASO(Imprime por consola el saludo de despedida, []() {
          PLATAFORMA->consola("Adios mundo!");
          return true;
      });
  };

  string reporte = CHIL->imprimirReporte();

  ASSERT_EQ(reporte, "Escenario: Primer escenario con dos pasos\n\n[OK] Imprime por consola el saludo de bienvenida - ejecuto en 49 useg\n[OK] Imprime por consola el saludo de despedida - ejecuto en 100 useg\n\n");
}

bool saludoDeComienzo() {
    PLATAFORMA->consola("Hola mundo!");
    return true;
}

bool saludoDeDespedida() {
    PLATAFORMA->consola("Hola mundo!");
    return true;
}

bool pasoFallidoPorConfiguracion() {
    return false;
}

TEST_F(PruebasDeChil, deberiaMostrarElResultadoDeTodosLosPasosUtilizandoFuncionesNombradasConSuResultado) {
    EXPECT_CALL(*plataforma, microsegundos()).WillOnce(Return(1L)).WillOnce(Return(50L)).WillOnce(Return(100L)).WillOnce(Return(200L));
    EXPECT_CALL(*plataforma, consola(_)).Times(AtLeast(2));

    ESCENARIO(Primer escenario con dos pasos){
        PASO(Imprime por consola el saludo de bienvenida, saludoDeComienzo);
        PASO(Imprime por consola el saludo de despedida, saludoDeDespedida);
    };

    string reporte = CHIL->imprimirReporte();

    ASSERT_EQ(reporte, "Escenario: Primer escenario con dos pasos\n\n[OK] Imprime por consola el saludo de bienvenida - ejecuto en 49 useg\n[OK] Imprime por consola el saludo de despedida - ejecuto en 100 useg\n\n");
}

TEST_F(PruebasDeChil, deberiaMostrarElResumenDeLaEjecucion) {
    EXPECT_CALL(*plataforma, microsegundos()).WillRepeatedly(Return(1L));
    EXPECT_CALL(*plataforma, consola(_)).WillRepeatedly(Return());

    ESCENARIO(Primer escenario con dos pasos){
        PASO(Imprime por consola el saludo de bienvenida, saludoDeComienzo);
        PASO(Imprime por consola el saludo de despedida, saludoDeDespedida);
    }

    ESCENARIO(Segundo escenario con dos pasos){
        PASO(FallaElPasoPorConfiguracion, pasoFallidoPorConfiguracion);
        PASO(Imprime por consola el saludo de despedida, saludoDeDespedida);
    }

    string reporte = CHIL->imprimirResumen();

    ASSERT_EQ(reporte, "Completados: 2, Exitosos: 1, Fallidos: 1");
}

TEST_F(PruebasDeChil, deberiaMostrarTodosLosEscenariosYElResumenAlFinalizarLasPruebas) {
    EXPECT_CALL(*plataforma, microsegundos())
                                    .WillOnce(Return(1L))
                                    .WillOnce(Return(50L))
                                    .WillOnce(Return(100L))
                                    .WillOnce(Return(200L))
                                    .WillOnce(Return(300L))
                                    .WillOnce(Return(410L))
                                    .WillRepeatedly(Return(500L));

    ESCENARIO(Primer escenario con dos pasos){
        PASO(Imprime por consola el saludo de bienvenida, saludoDeComienzo);
        PASO(Imprime por consola el saludo de despedida, saludoDeDespedida);
    }

    ESCENARIO(Segundo escenario con dos pasos){
        PASO(FallaElPasoPorConfiguracion, pasoFallidoPorConfiguracion);
        PASO(Imprime por consola el saludo de despedida, saludoDeDespedida);
    }

    EXPECT_CALL(*plataforma, consola(testing::ContainsRegex(
            "Escenario: Primer escenario con dos pasos\n\n"
            "\\[OK\\] Imprime por consola el saludo de bienvenida - ejecuto en 49 useg\n"
            "\\[OK\\] Imprime por consola el saludo de despedida - ejecuto en 100 useg\n\n"
            "Escenario: Segundo escenario con dos pasos\n\n"
            "\\[FALLO\\] FallaElPasoPorConfiguracion - ejecuto en 110 useg\n"
            "\\[OK\\] Imprime por consola el saludo de despedida - ejecuto en 0 useg\n"
            "\\*\\*\\* ESCENARIO FALLIDO \\*\\*\\*\n\n"))).Times(AtLeast(1));
    EXPECT_CALL(*plataforma, consola(testing::ContainsRegex("Completados: 2, Exitosos: 1, Fallidos: 1")));
    EXPECT_CALL(*plataforma, consola(testing::ContainsRegex("Fin de pruebas con CHIL")));

    FIN_DE_PRUEBAS;
}