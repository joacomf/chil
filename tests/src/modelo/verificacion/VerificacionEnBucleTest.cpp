#include "compartido-tests.h"

const int PIN_BOTON = 5;
PlataformaMock *plataformaMock;

void dadoQueChilEstaActivo();
void dadoQueElTiempoAvanzaEnMilisegundos();
void dadoQueUnaLecturaRetorna1EnElCuartoIntento();
void dadoQueLaLecturaSiempreRetorna0();

TEST(VerificacionEnBucleTest, verificaEnModoSondeoUnaAccionDurante200milisegundos)
{
    dadoQueChilEstaActivo();
    dadoQueElTiempoAvanzaEnMilisegundos();
    dadoQueUnaLecturaRetorna1EnElCuartoIntento();

    ASSERT_NO_THROW(
            comprobar([]() {
                return PLATAFORMA->leer(PIN_BOTON) == 1;
            })
                    ->durante(200)
                    ->seHayaEjecutado();
    );

    delete plataformaMock;
}

TEST(VerificacionEnBucleTest, lanzaExcepcionSiLaAccionNuncaSeComprueba)
{
    dadoQueChilEstaActivo();
    dadoQueElTiempoAvanzaEnMilisegundos();
    dadoQueLaLecturaSiempreRetorna0();

    ASSERT_THROW(
            comprobar([]() {
                return PLATAFORMA->leer(PIN_BOTON) == 1;
            })
                    ->durante(200)
                    ->seHayaEjecutado(), AccionNoEjecutadaExcepcion);

    delete plataformaMock;
}


void dadoQueChilEstaActivo() {
    plataformaMock = new PlataformaMock();
    NUEVO_CHIL_CON(plataformaMock);
}

void dadoQueElTiempoAvanzaEnMilisegundos() {
    EXPECT_CALL(*plataformaMock, milisegundos())
            .WillOnce(Return(1L))
            .WillOnce(Return(50L))
            .WillOnce(Return(100L))
            .WillOnce(Return(150L))
            .WillOnce(Return(199L))
            .WillRepeatedly(Return(220L));
}

void dadoQueUnaLecturaRetorna1EnElCuartoIntento() {
    EXPECT_CALL(*plataformaMock, leer(_))
            .WillOnce(Return(0))
            .WillOnce(Return(0))
            .WillOnce(Return(0))
            .WillOnce(Return(1));
}

void dadoQueLaLecturaSiempreRetorna0() {
    EXPECT_CALL(*plataformaMock, leer(_)).WillRepeatedly(Return(0));
}
