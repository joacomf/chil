#include <climits>
#include "gtest/gtest.h"
#include "modelo/verificacion/Verificacion.h"
#include "modelo/verificacion/excepciones/ValoresDistintosExcepcion.h"

TEST(VerificacionTest, verificaUnValorEnteroCorrectamente) {
    ASSERT_NO_THROW(verificar<int>(5).esIgualA(5));
}

TEST(VerificacionTest, verificaUnValorDobleCorrectamente) {
    ASSERT_NO_THROW(verificar<double>(5.2).esIgualA(5.2));
}

TEST(VerificacionTest, verificaUnValorLongCorrectamente) {
    ASSERT_NO_THROW(verificar<long>(1239292399123).esIgualA(1239292399123));
}

TEST(VerificacionTest, verificaUnValorShortCorrectamente) {
    ASSERT_NO_THROW(verificar<short>(-12).esIgualA(-12));
}

TEST(VerificacionTest, verificaLosValoresExtremosDeTodosLosTiposNumericos) {
    ASSERT_NO_THROW(verificar<signed char>(SCHAR_MIN).esIgualA(-128));
    ASSERT_NO_THROW(verificar<signed char>(SCHAR_MAX).esIgualA(127));
    ASSERT_NO_THROW(verificar<unsigned char>(UCHAR_MAX).esIgualA(255));
    ASSERT_NO_THROW(verificar<char>(CHAR_MIN).esIgualA(-128));
    ASSERT_NO_THROW(verificar<char>(CHAR_MAX).esIgualA(127));

    ASSERT_NO_THROW(verificar<short>(SHRT_MIN).esIgualA(-32768));
    ASSERT_NO_THROW(verificar<short>(SHRT_MAX).esIgualA(32767));
    ASSERT_NO_THROW(verificar<unsigned short>(USHRT_MAX).esIgualA(65535));

    ASSERT_NO_THROW(verificar<int>(INT_MIN).esIgualA(-2147483648));
    ASSERT_NO_THROW(verificar<int>(INT_MAX).esIgualA(2147483647));
    ASSERT_NO_THROW(verificar<unsigned int>(UINT_MAX).esIgualA(4294967295));

    ASSERT_NO_THROW(verificar<long>(LONG_MIN).esIgualA(-9223372036854775808U));
    ASSERT_NO_THROW(verificar<long>(LONG_MAX).esIgualA(9223372036854775807L));
    ASSERT_NO_THROW(verificar<unsigned long>(ULONG_MAX).esIgualA(18446744073709551615U));

    ASSERT_NO_THROW(verificar<long long>(LONG_LONG_MIN).esIgualA(-9223372036854775808U));
    ASSERT_NO_THROW(verificar<long long>(LONG_LONG_MAX).esIgualA(9223372036854775807L));
    ASSERT_NO_THROW(verificar<unsigned long long>(ULONG_LONG_MAX).esIgualA(18446744073709551615U));
}

TEST(VerificacionTest, lanzaExcepcionSiLosValoresAComparaNoSonIguales) {
    ASSERT_THROW(verificar<int>(2).esIgualA(5), ValoresDistintosExcepcion<int>);
}

TEST(VerificacionTest, recibeMensajeDescriptivoSilanzaExcepcionEnCasoDeQueLosValoresAComparaNoSonIguales) {
    try {
        verificar<double>(2.23).esIgualA(5.21);
    } catch (ValoresDistintosExcepcion<double>& e) {
        ASSERT_EQ(e.obtenerMensaje(), "Se esperaba el valor: \n5.210000\nPero se recibio el valor: \n2.230000\n");
    }
}