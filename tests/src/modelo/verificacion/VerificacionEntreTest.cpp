#include "compartido-tests.h"

TEST(VerificacionEntreValoresTest, verificaUnValorEsteEntreDosValoresCorrectamente) {
    ASSERT_NO_THROW(verificar<int>(5)->entre(4, 6));
    ASSERT_NO_THROW(verificar<int>(5)->entre(5, 5));
    ASSERT_NO_THROW(verificar<long>(123123)->entre(1, 123123));
    ASSERT_NO_THROW(verificar<long>(123123)->entre(1, 200000));
    ASSERT_NO_THROW(verificar<double>(5.2)->entre(4.3, 6.0));

    ASSERT_THROW(verificar<int>(2)->entre(5, 6), ValorNoEstaEntreExcepcion<int>);
    ASSERT_THROW(verificar<long>(2232L)->entre(2233L, 2233L), ValorNoEstaEntreExcepcion<long>);
    ASSERT_THROW(verificar<double>(2.2)->entre(5123.42, 5123.42), ValorNoEstaEntreExcepcion<double>);
}

TEST(VerificacionEntreValoresTest, alNoEstarEntre2ValoresSeLanzaExepcionInformandoElProblema) {
    try {
        verificar<double>(2.2)->entre(3.3, 4.4);
    } catch (ValorNoEstaEntreExcepcion<double>& excepcion) {
        ASSERT_EQ(excepcion.obtenerMensaje(),"Se esperaba el valor: \n2.2\nEste entre: \n3.3 y 4.4\nPero no lo esta\n");
    }
}
