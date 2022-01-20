#include "gtest/gtest.h"
#include "modelo/verificacion/Verificacion.h"
#include "modelo/verificacion/excepciones/ValoresDistintosExcepcion.h"

TEST(VerificacionTest, verificaUnValorEnteroCorrectamente) {
    ASSERT_NO_THROW(verificar<int>(5).esIgualA(5));
}

TEST(VerificacionTest, verificaUnValorDobleCorrectamente) {
    ASSERT_NO_THROW(verificar<double>(5.2).esIgualA(5.2));
}

TEST(VerificacionTest, lanzaExcepcionSiLosValoresAComparaNoSonIguales) {
    ASSERT_THROW(verificar<int>(2).esIgualA(5), ValoresDistintosExcepcion);
}