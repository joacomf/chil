#include "compartido-tests.h"

TEST(VerificacionTest, verificaUnValorMayorAOtroCorrectamente) {
    ASSERT_NO_THROW(verificar<int>(5)->esMayorA(4));
    ASSERT_NO_THROW(verificar<long>(123123)->esMayorA(3334));
    ASSERT_NO_THROW(verificar<double>(5.2)->esMayorA(4.3));

    ASSERT_THROW(verificar<int>(2)->esMayorA(5), ValorNoEsMayorExcepcion<int>);
    ASSERT_THROW(verificar<long>(2232L)->esMayorA(2232L), ValorNoEsMayorExcepcion<long>);
    ASSERT_THROW(verificar<double>(2.2)->esMayorA(5123.4232), ValorNoEsMayorExcepcion<double>);
}

TEST(VerificacionTest, alNoSerMayorSeLanzaExepcionInformandoElProblema) {
    try {
        verificar<double>(2.2)->esMayorA(5123.4232);
    } catch (ValorNoEsMayorExcepcion<double>& excepcion) {
        ASSERT_EQ(excepcion.obtenerMensaje(),"Se esperaba que el valor 2.2 sea mayor a 5123.42 pero no lo fue");
    }
}

TEST(VerificacionTest, verificaUnValorMayorOIgualAOtroCorrectamente) {
    ASSERT_NO_THROW(verificar<int>(5)->esMayorOIgualA(4));
    ASSERT_NO_THROW(verificar<long>(123123)->esMayorOIgualA(123123));
    ASSERT_NO_THROW(verificar<double>(5.2)->esMayorOIgualA(5.2));

    ASSERT_THROW(verificar<int>(5)->esMayorOIgualA(6), ValorNoEsMayorOIgualExcepcion<int>);
    ASSERT_THROW(verificar<long>(2232L)->esMayorOIgualA(22321L), ValorNoEsMayorOIgualExcepcion<long>);
    ASSERT_THROW(verificar<double>(2.2)->esMayorOIgualA(2.2000000001), ValorNoEsMayorOIgualExcepcion<double>);
}

TEST(VerificacionTest, alNoSerMayorOIgualSeLanzaExepcionInformandoElProblema) {
    try {
        verificar<double>(2.2)->esMayorOIgualA(5123.4232);
    } catch (ValorNoEsMayorOIgualExcepcion<double>& excepcion) {
        ASSERT_EQ(excepcion.obtenerMensaje(), "Se esperaba que el valor 2.2 sea mayor o igual a 5123.42 pero no lo fue");
    }
}

TEST(VerificacionTest, verificaUnValorMenorAOtroCorrectamente) {
    ASSERT_NO_THROW(verificar<int>(4)->esMenorA(5));
    ASSERT_NO_THROW(verificar<long>(1)->esMenorA(123123));
    ASSERT_NO_THROW(verificar<double>(5.2)->esMenorA(5.21));

    ASSERT_THROW(verificar<int>(21)->esMenorA(5), ValorNoEsMenorExcepcion<int>);
    ASSERT_THROW(verificar<long>(42235)->esMenorA(42235), ValorNoEsMenorExcepcion<long>);
    ASSERT_THROW(verificar<double>(5123.2)->esMenorA(3.4232), ValorNoEsMenorExcepcion<double>);
}

TEST(VerificacionTest, alNoSerMenorSeLanzaExepcionInformandoElProblema) {
    try {
        verificar<double>(5123.5)->esMenorA(5123.4232);
    } catch (ValorNoEsMenorExcepcion<double>& excepcion) {
        ASSERT_EQ(excepcion.obtenerMensaje(), "Se esperaba que el valor 5123.5 sea menor a 5123.42 pero no lo fue");
    }
}

TEST(VerificacionTest, verificaUnValorMenorOIgualAOtroCorrectamente) {
    ASSERT_NO_THROW(verificar<int>(4)->esMenorOIgualA(5));
    ASSERT_NO_THROW(verificar<long>(1)->esMenorOIgualA(123123));
    ASSERT_NO_THROW(verificar<double>(5.2)->esMenorOIgualA(5.21));

    ASSERT_THROW(verificar<int>(21)->esMenorOIgualA(5), ValorNoEsMenorOIgualExcepcion<int>);
    ASSERT_THROW(verificar<long>(42236)->esMenorOIgualA(42235), ValorNoEsMenorOIgualExcepcion<long>);
    ASSERT_THROW(verificar<double>(5123.2)->esMenorOIgualA(3.4232), ValorNoEsMenorOIgualExcepcion<double>);
}

TEST(VerificacionTest, alNoSerMenorOIgualSeLanzaExepcionInformandoElProblema) {
    try {
        verificar<double>(5123.4)->esMenorOIgualA(5123.4232);
    } catch (ValorNoEsMenorOIgualExcepcion<double>& excepcion) {
        ASSERT_EQ(excepcion.obtenerMensaje(), "Se esperaba que el valor 5123.5 sea menor o igual a 5123.42 pero no lo fue");
    }
}