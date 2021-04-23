#include <PuntoDeEntrada.cpp>
#include "gtest/gtest.h"

TEST(PuntoDeEntrada, deberiaCrearPuntoDeEntradaConRutaEspecificada) {
    PuntoDeEntrada* puntoDeEntrada = new PuntoDeEntrada("numero-primo");

    ASSERT_EQ(puntoDeEntrada->obtenerRuta(), "numero-primo");
}