#include <modelo/Paso.h>
#include "gtest/gtest.h"

bool funcionExitosa(){ return true; }
bool funcionFallida(){ return false; }

TEST(PasoTest, seGeneraUnResultadoConNombrePaso) {
  auto* paso = new Paso("Envia comando a pin 13", funcionExitosa);

  string nombreDelPaso = paso->obtenerNombre();

  ASSERT_EQ(nombreDelPaso, "Envia comando a pin 13");
}

TEST(PasoTest, seObtieneElTiempoLuegoDeRegistrarInicioYFin) {
  auto* paso = new Paso("Envia comando a pin 13", funcionExitosa);

  paso->inicio(102450L);
  paso->fin(103000L);

  unsigned long tiempo = paso->tiempo();

  ASSERT_EQ(tiempo, 550L);
}

TEST(PasoTest, alTenerMostrarUnResultadoOKSeExpresaElExitoNombreYTiempoTranscurrido) {
  auto* paso = new Paso("Envia comando a pin 13", funcionFallida);

  paso->inicio(103540L);
  paso->fin(103580L);
  paso->ejecutar();

  string resultado = paso->mostrar();

  ASSERT_EQ(resultado, "[FALLO] Envia comando a pin 13 - ejecuto en 40 useg");
}