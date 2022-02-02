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

TEST(PuntoDeEntrada, deberiaConfigurarRespuestaConTipoYCodigoDeRespuesta) {
    auto* puntoDeEntrada = new PuntoDeEntrada("ping");

    puntoDeEntrada->configurarRespuesta("Hola mundo!", "application/json", 202);

    ASSERT_EQ(puntoDeEntrada->obtenerRespuesta(), "Hola mundo!");
    ASSERT_EQ(puntoDeEntrada->obtenerTipo(), "application/json");
    ASSERT_EQ(puntoDeEntrada->obtenerCodigoDeRespuesta(), 202);
}