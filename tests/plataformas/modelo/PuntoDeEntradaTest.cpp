#include <PuntoDeEntrada.cpp>
#include "gtest/gtest.h"

TEST(PuntoDeEntrada, deberiaCrearPuntoDeEntradaConRutaEspecificadaYMetodoGETPorDefault) {
    auto* puntoDeEntrada = new PuntoDeEntrada("numero-primo");

    ASSERT_EQ(puntoDeEntrada->obtenerRuta(), "numero-primo");
    ASSERT_EQ(puntoDeEntrada->obtenerMetodo(), GET);
}

TEST(PuntoDeEntrada, deberiaCrearPuntoDeEntradaConRutaEspecificadaYMetodoEspecificado) {
    auto* puntoDeEntrada = new PuntoDeEntrada("numero-primo", POST);

    ASSERT_EQ(puntoDeEntrada->obtenerRuta(), "numero-primo");
    ASSERT_EQ(puntoDeEntrada->obtenerMetodo(), POST);
}
