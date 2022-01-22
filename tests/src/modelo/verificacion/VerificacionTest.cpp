#include <climits>
#include "gtest/gtest.h"
#include "modelo/verificacion/Verificacion.h"

TEST(VerificacionTest, verificaUnValorEnteroCorrectamente) {
    ASSERT_NO_THROW(verificar<int>(5)->esIgualA(5));
    ASSERT_THROW(verificar<int>(2)->esIgualA(5), ValoresDistintosExcepcion<int>);
}

TEST(VerificacionTest, verificaUnValorConComaFlotanteCorrectamente) {
    ASSERT_NO_THROW(verificar<float>(123125.12322f)->esIgualA(123125.12322f));
    ASSERT_THROW(verificar<float>(123125.12322f)->esIgualA(12312.12322f), ValoresDistintosExcepcion<float>);
}

TEST(VerificacionTest, verificaUnValorDobleCorrectamente) {
    ASSERT_NO_THROW(verificar<double>(5.22322e+200)->esIgualA(5.22322e+200));
    ASSERT_THROW(verificar<double>(5.22322e+200)->esIgualA(5.22322e+199), ValoresDistintosExcepcion<double>);
}

TEST(VerificacionTest, verificaUnValorDobleConDistintaPrecisionCorrectamente) {
    ASSERT_NO_THROW(verificar<double>(5.2000)->esIgualA(5.2));
}

TEST(VerificacionTest, verificaUnValorLongCorrectamente) {
    ASSERT_NO_THROW(verificar<long>(1239292399123)->esIgualA(1239292399123));
    ASSERT_THROW(verificar<long>(1239292399123)->esIgualA(3339292399123), ValoresDistintosExcepcion<long>);
}

TEST(VerificacionTest, verificaUnValorShortCorrectamente) {
    ASSERT_NO_THROW(verificar<short>(-12)->esIgualA(-12));
    ASSERT_THROW(verificar<short>(-122)->esIgualA(312), ValoresDistintosExcepcion<short>);
}

TEST(VerificacionTest, verificaLosValoresExtremosDeTodosLosTiposNumericosEnteros) {
    ASSERT_NO_THROW(verificar<signed char>(SCHAR_MIN)->esIgualA(-128));
    ASSERT_NO_THROW(verificar<signed char>(SCHAR_MAX)->esIgualA(127));
    ASSERT_NO_THROW(verificar<unsigned char>(UCHAR_MAX)->esIgualA(255));
    ASSERT_NO_THROW(verificar<char>(CHAR_MIN)->esIgualA(-128));
    ASSERT_NO_THROW(verificar<char>(CHAR_MAX)->esIgualA(127));

    ASSERT_NO_THROW(verificar<short>(SHRT_MIN)->esIgualA(-32768));
    ASSERT_NO_THROW(verificar<short>(SHRT_MAX)->esIgualA(32767));
    ASSERT_NO_THROW(verificar<unsigned short>(USHRT_MAX)->esIgualA(65535));

    ASSERT_NO_THROW(verificar<int>(INT_MIN)->esIgualA(-2147483648));
    ASSERT_NO_THROW(verificar<int>(INT_MAX)->esIgualA(2147483647));
    ASSERT_NO_THROW(verificar<unsigned int>(UINT_MAX)->esIgualA(4294967295));

    ASSERT_NO_THROW(verificar<long>(LONG_MIN)->esIgualA(-9223372036854775808U));
    ASSERT_NO_THROW(verificar<long>(LONG_MAX)->esIgualA(9223372036854775807L));
    ASSERT_NO_THROW(verificar<unsigned long>(ULONG_MAX)->esIgualA(18446744073709551615U));

    ASSERT_NO_THROW(verificar<long long>(LONG_LONG_MIN)->esIgualA(-9223372036854775808U));
    ASSERT_NO_THROW(verificar<long long>(LONG_LONG_MAX)->esIgualA(9223372036854775807L));
    ASSERT_NO_THROW(verificar<unsigned long long>(ULONG_LONG_MAX)->esIgualA(18446744073709551615U));
}

TEST(VerificacionTest, verificaLosValoresNumericosDeTodosLosTiposEnterosConComaFlotante){
    ASSERT_NO_THROW(verificar<float>(1.17549e-038)->esIgualA(1.17549e-038));
    ASSERT_NO_THROW(verificar<float>(3.40282e+038f)->esIgualA(3.40282e+038f));

    ASSERT_NO_THROW(verificar<double>(2.22507e-308)->esIgualA(2.22507e-308));
    ASSERT_NO_THROW(verificar<double>(1.79769e+308)->esIgualA(1.79769e+308));

    ASSERT_NO_THROW(verificar<long double>(2.22507e-308)->esIgualA(2.22507e-308));
    ASSERT_NO_THROW(verificar<long double>(1.79769e+308)->esIgualA(1.79769e+308));
}

TEST(VerificacionTest, verificaUnValorConstCharAst) {
    ASSERT_NO_THROW(verificar("texto")->esIgualA("texto"));
    ASSERT_THROW(verificar("texto")->esIgualA("notexto"), ValoresDistintosExcepcion<const char*>);
}

TEST(VerificacionTest, recibeMensajeDescriptivoSilanzaExcepcionEnCasoDeQueLosValoresAComparaNoSonIguales) {
    try {
        verificar<double>(2.23)->esIgualA(5.21);
    } catch (ValoresDistintosExcepcion<double>& e) {
        ASSERT_EQ(e.obtenerMensaje(), "Se esperaba el valor: \n5.210000\nPero se recibio el valor: \n2.230000\n");
    }
}

TEST(VerificacionTest, recibeMensajeDescriptivoSilanzaExcepcionEnCasoDeQueLosLiteralesAComparaNoSonIguales) {
    try {
        verificar("valores")->esIgualA("muy distintos");
    } catch (ValoresDistintosExcepcion<const char*>& e) {
        ASSERT_EQ(e.obtenerMensaje(), "Se esperaba el valor: \nmuy distintos\nPero se recibio el valor: \nvalores\n");
    }
}