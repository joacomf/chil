#include "compartido-tests.h"

TEST(VerificacionTest, verificaUnValorMayorAOtroCorrectamente) {
    ASSERT_NO_THROW(verificar<int>(5)->esMayorA(4));
    ASSERT_NO_THROW(verificar<long>(123123)->esMayorA(3334));
    ASSERT_NO_THROW(verificar<double>(5.2)->esMayorA(4.3));

    ASSERT_THROW(verificar<int>(2)->esMayorA(5), ValorEsMenorExcepcion<int>);
    ASSERT_THROW(verificar<long>(2232L)->esMayorA(2232L), ValorEsMenorExcepcion<long>);
    ASSERT_THROW(verificar<double>(2.2)->esMayorA(5123.4232), ValorEsMenorExcepcion<double>);
}

TEST(VerificacionTest, alNoSerMayorSeLanzaExepcionInformandoElProblema) {
    try {
        verificar<double>(2.2)->esMayorA(5123.4232);
    } catch (ValorEsMenorExcepcion<double>& excepcion) {
        ASSERT_EQ(excepcion.obtenerMensaje(), "Se esperaba el valor: \n5123.42\nSea mayor a: \n2.2\nPero no lo es\n");
    }
}

TEST(VerificacionTest, verificaUnValorMenorAOtroCorrectamente) {
    ASSERT_NO_THROW(verificar<int>(4)->esMenorA(5));
    ASSERT_NO_THROW(verificar<long>(1)->esMenorA(123123));
    ASSERT_NO_THROW(verificar<double>(5.2)->esMenorA(5.21));

    ASSERT_THROW(verificar<int>(21)->esMenorA(5), ValorEsMayorExcepcion<int>);
    ASSERT_THROW(verificar<long>(42235)->esMenorA(42235), ValorEsMayorExcepcion<long>);
    ASSERT_THROW(verificar<double>(5123.2)->esMenorA(3.4232), ValorEsMayorExcepcion<double>);
}

TEST(VerificacionTest, alNoSerMenorSeLanzaExepcionInformandoElProblema) {
    try {
        verificar<double>(5123.2)->esMenorA(5123.4232);
    } catch (ValorEsMayorExcepcion<double>& excepcion) {
        ASSERT_EQ(excepcion.obtenerMensaje(), "Se esperaba el valor: \n9922.2\nSea menor a: \n5123.42\nPero no lo es\n");
    }
}