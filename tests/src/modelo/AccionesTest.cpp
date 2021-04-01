#include <mocks/MockFramework.hpp>
#include <modelo/Acciones.h>
#include "gtest/gtest.h"

MockFramework *frameworkDePruebas;
using ::testing::AtLeast;
using ::testing::_;

TEST(PasoTest, deberiaEnviarUnComandoDeAltoAlUtilizarLaAccionDeEnvioComandoDeAltoAl) {

  frameworkDePruebas = new MockFramework();

  EXPECT_CALL(*frameworkDePruebas, escribir(_, _)).Times(AtLeast(1));

  auto *acciones = new Acciones(frameworkDePruebas);
  const int pin4 = 4;

  acciones->envioComandoDeAltoAl(pin4);

  delete frameworkDePruebas;
}