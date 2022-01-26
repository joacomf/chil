#include "compartido-tests.h"

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

void valorNoIgualAOtro() {
    verificar(4)->esIgualA(2);
}

TEST(PasoTest, ejecutaMetodoVoidQueLanzaExcepcionPorMedioDeUnaVerificacion) {
    auto* paso = new Paso("Envia comando a pin 13", valorNoIgualAOtro);

    paso->inicio(103540L);
    paso->fin(103580L);
    paso->ejecutar();

    ASSERT_EQ(paso->esExitoso(), false);
    ASSERT_EQ(paso->detalleDeError(), "Se esperaba el valor: \n"
                         "4\n"
                         "Sea igual a: \n"
                         "2\n"
                         "Pero no lo fue\n");}

TEST(PasoTest, alEjecutarUnPasoConLaLibreriaDeVerificacionGuardaElErrorDelFallo) {
    auto* paso = new Paso("Recibe valor 4 en el pin", valorNoIgualAOtro);

    paso->inicio(103540L);
    paso->ejecutar();
    paso->fin(103580L);

    string detalleError = paso->detalleDeError();
    string resultado = paso->mostrar();

    ASSERT_EQ(detalleError, "Se esperaba el valor: \n"
                         "4\n"
                         "Sea igual a: \n"
                         "2\n"
                         "Pero no lo fue\n");
    ASSERT_EQ(resultado, "[FALLO] Recibe valor 4 en el pin - ejecuto en 40 useg\n"
                         "\tDetalle: Se esperaba el valor: \n"
                         "4\n"
                         "Sea igual a: \n"
                         "2\n"
                         "Pero no lo fue\n");
}