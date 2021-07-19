#include <mocks/PlataformaMock.hpp>
#include "gtest/gtest.h"
#include "modelo/Escenario.h"

using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;

bool pasoExitoso(){ return true;}
bool pasoFallido(){ return false;}

TEST(EscenarioTest, alGenerarReporteNoTieneNingunResultado) {
  auto* escenario = new Escenario("Escenario nulo");
  string resultado = escenario->imprimirResultado();
  int cantidadDePasos = escenario->obtenerCantidadPasos();

  ASSERT_EQ(resultado, "Escenario: Escenario nulo\n\n");
  ASSERT_EQ(cantidadDePasos, 0);
}

TEST(EscenarioTest, alMostrarElReporteFinalSeListaEnUnaLineaCadaResultado) {

  auto *framework = new PlataformaMock();
  auto* escenario = new Escenario("Deja de recibir comando en pin 1 para pasar comando al pin 12");

  EXPECT_CALL(*framework, microsegundos())
          .WillOnce(Return(0L))
          .WillOnce(Return(100L))
          .WillOnce(Return(150L))
          .WillOnce(Return(190L))
          .WillOnce(Return(230L))
          .WillOnce(Return(400L));

  auto *paso1 = new Paso("Recibe comando en el pin 1", pasoExitoso);
  auto *paso2 = new Paso("Deja de recibir comando en el pin 1", pasoExitoso);
  auto *paso3 = new Paso("Recibe comando en el pin 12", pasoExitoso);

  escenario->nuevo(paso1);
  escenario->nuevo(paso2);
  escenario->nuevo(paso3);

  escenario->finalizar(framework);

  int cantidadDeResultados = escenario->obtenerCantidadPasos();

  string reporteFinal = escenario->imprimirResultado();

  ASSERT_EQ(cantidadDeResultados, 3);
  ASSERT_EQ("Escenario: Deja de recibir comando en pin 1 para pasar comando al pin 12\n\n"
            "[OK] Recibe comando en el pin 1 - ejecuto en 100 useg\n"
            "[OK] Deja de recibir comando en el pin 1 - ejecuto en 40 useg\n"
            "[OK] Recibe comando en el pin 12 - ejecuto en 170 useg\n", reporteFinal);

  delete framework;
}

TEST(EscenarioTest, resaltaElIndicadorDeEscenarioFallidoSiFallaAlgunoDeLosPasos) {

    auto *framework = new PlataformaMock();
    auto* escenario = new Escenario("Deja de recibir comando en pin 1 para pasar comando al pin 12");

    EXPECT_CALL(*framework, microsegundos())
            .WillOnce(Return(0L))
            .WillOnce(Return(100L))
            .WillOnce(Return(150L))
            .WillOnce(Return(190L))
            .WillOnce(Return(230L))
            .WillOnce(Return(400L));

    auto *paso1 = new Paso("Recibe comando en el pin 1", pasoExitoso);
    auto *paso2 = new Paso("Deja de recibir comando en el pin 1", pasoFallido);
    auto *paso3 = new Paso("Recibe comando en el pin 12", pasoFallido);

    escenario->nuevo(paso1);
    escenario->nuevo(paso2);
    escenario->nuevo(paso3);

    escenario->finalizar(framework);

    string reporteFinal = escenario->imprimirResultado();

    ASSERT_EQ(escenario->esExitoso(), false);
    ASSERT_EQ("Escenario: Deja de recibir comando en pin 1 para pasar comando al pin 12\n\n"
              "[OK] Recibe comando en el pin 1 - ejecuto en 100 useg\n"
              "[FALLO] Deja de recibir comando en el pin 1 - ejecuto en 40 useg\n"
              "[FALLO] Recibe comando en el pin 12 - ejecuto en 170 useg\n"
              "*** ESCENARIO FALLIDO ***\n", reporteFinal);

    delete framework;
}