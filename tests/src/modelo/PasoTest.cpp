#include <modelo/Paso.h>
#include "gtest/gtest.h"

TEST(ResultadoTest, seGeneraUnResultadoConNombrePaso) {
  auto* paso = new Paso("Envia comando a pin 13", [](){});

  string nombreDelPaso = paso->obtenerNombre();

  ASSERT_EQ(nombreDelPaso, "Envia comando a pin 13");
}

TEST(ResultadoTest, seObtieneElTiempoLuegoDeRegistrarInicioYFin) {
  auto* paso = new Paso("Envia comando a pin 13", [](){});

  paso->inicio(102450L);
  paso->fin(103000L);

  unsigned long tiempo = paso->tiempo();

  ASSERT_EQ(tiempo, 550L);
}

TEST(ResultadoTest, alTenerMostrarUnResultadoOKSeExpresaElExitoNombreYTiempoTranscurrido) {
  auto* paso = new Paso("Envia comando a pin 13", [](){});

  paso->inicio(103540L);
  paso->fin(103580L);
  paso->exito(false);

  string resultado = paso->mostrar();

  ASSERT_EQ(resultado, "[FALLO] Envia comando a pin 13 - ejecuto en 40 useg");
}