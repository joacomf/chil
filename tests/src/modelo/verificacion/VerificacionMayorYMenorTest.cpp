#include "compartido-tests.h"

TEST(VerificacionTest, verificaUnValorMayorAOtroCorrectamente) {
    ASSERT_NO_THROW(verificar<int>(5)->esMayorA(4));
    ASSERT_NO_THROW(verificar<long>(123123)->esMayorA(3334));
    ASSERT_NO_THROW(verificar<double>(5.2)->esMayorA(4.3));

    ASSERT_THROW(verificar<int>(2)->esMayorA(5), ValorEsMenorExcepcion<int>);
    ASSERT_THROW(verificar<long>(2232)->esMayorA(511111), ValorEsMenorExcepcion<long>);
    ASSERT_THROW(verificar<double>(2.2)->esMayorA(5123.4232), ValorEsMenorExcepcion<double>);
}

TEST(VerificacionTest, alNoSerMayorSeLanzaExepcionInformandoElProblema) {
    try {
        verificar<double>(2.2)->esMayorA(5123.4232);
    } catch (ValorEsMenorExcepcion<double>& excepcion) {
        ASSERT_EQ(excepcion.obtenerMensaje(), "Se esperaba el valor: \n5123.42\nSea mayor a: \n2.2\nPero es menor o igual\n");
    }
}