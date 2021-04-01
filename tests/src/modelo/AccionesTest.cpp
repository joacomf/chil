#include <mocks/MockFramework.hpp>
#include <modelo/Acciones.h>
#include "gtest/gtest.h"

MockFramework *frameworkDePruebas;
using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;

TEST(PasoTest, deberiaEnviarUnComandoDeAltoAlUtilizarLaAccionDeEnvioComandoDeAltoAl) {

  frameworkDePruebas = new MockFramework();

  EXPECT_CALL(*frameworkDePruebas, escribir(_, _)).Times(AtLeast(1));

  auto *acciones = new Acciones(frameworkDePruebas);
  const int pin4 = 4;

  acciones->envioBanderaDeAltoAl(pin4);

  delete frameworkDePruebas;
}

TEST(PasoTest, deberiaObtenerLaLecturaDeUnComandoAlUtilizarLaAccionDeLectura) {

  frameworkDePruebas = new MockFramework();

  EXPECT_CALL(*frameworkDePruebas, leer(_))
              .Times(AtLeast(1))
              .WillOnce(Return(29));

  auto *acciones = new Acciones(frameworkDePruebas);
  const int pin4 = 4;

  int valorObtenido = acciones->leoValorEn(pin4);

  ASSERT_EQ(valorObtenido, 29);

  delete frameworkDePruebas;
}