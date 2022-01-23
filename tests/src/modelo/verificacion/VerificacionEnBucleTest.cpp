#include "compartido-tests.h"

const int PIN_BOTON = 5;
PlataformaMock *plataformaMock;

void dadoQueChilEstaActivo();
void dadoQueElTiempoAvanzaEnMilisegundos();
void dadoQueUnaLecturaRetorna1EnElCuartoIntento();
void dadoQueLaLecturaSiempreRetorna0();
void dadoQueSePuedeLlamarADemorar();
void dadoQueSeLlamara3VecesADemoraDe2Milisegundos();

TEST(VerificacionEnBucleTest, verificaEnModoSondeoUnaAccionDurante200milisegundos)
{
    dadoQueChilEstaActivo();
    dadoQueElTiempoAvanzaEnMilisegundos();
    dadoQueUnaLecturaRetorna1EnElCuartoIntento();
    dadoQueSePuedeLlamarADemorar();

    ASSERT_NO_THROW(
            comprobar([]() {
                return PLATAFORMA->leer(PIN_BOTON) == 1;
            })
            ->durante(200)
            ->seHayaEjecutado();
    );

    delete plataformaMock;
}

TEST(VerificacionEnBucleTest, verificaEnModoSondeoUnaAccionDurante200milisegundosYConUnIntervaloDeEsperaDe20MS)
{
    dadoQueChilEstaActivo();
    dadoQueElTiempoAvanzaEnMilisegundos();
    dadoQueUnaLecturaRetorna1EnElCuartoIntento();
    dadoQueSeLlamara3VecesADemoraDe2Milisegundos();

    ASSERT_NO_THROW(
            comprobar([]() {
                return PLATAFORMA->leer(PIN_BOTON) == 1;
            })
            ->durante(200)
            ->conIntervaloDe(2)
            ->seHayaEjecutado();
    );

    delete plataformaMock;
}

TEST(VerificacionEnBucleTest, lanzaExcepcionSiLaAccionNuncaSeComprueba)
{
    dadoQueChilEstaActivo();
    dadoQueElTiempoAvanzaEnMilisegundos();
    dadoQueLaLecturaSiempreRetorna0();
    dadoQueSePuedeLlamarADemorar();

    ASSERT_THROW(
            comprobar([]() {
                return PLATAFORMA->leer(PIN_BOTON) == 1;
            })
            ->durante(200)
            ->seHayaEjecutado(), AccionNoEjecutadaExcepcion);

    delete plataformaMock;
}

TEST(VerificacionEnBucleTest, elMensajeDeLaExcepcionLanzadaIndicaLasCaracteristicasDeLaVerificacionNoCumplida)
{
    dadoQueChilEstaActivo();
    dadoQueElTiempoAvanzaEnMilisegundos();
    dadoQueLaLecturaSiempreRetorna0();
    dadoQueSePuedeLlamarADemorar();


    try {
        comprobar([]() {
            return PLATAFORMA->leer(PIN_BOTON) == 1;
        })
        ->durante(201)
        ->conIntervaloDe(5)
        ->seHayaEjecutado();

    } catch (AccionNoEjecutadaExcepcion& excepcion) {
        ASSERT_EQ(excepcion.obtenerMensaje(), "La accion indicada no se corroboro en el periodo de 201ms con un intervalo de 5ms entre cada verificacion");
    }

    delete plataformaMock;
}


void dadoQueChilEstaActivo() {
    plataformaMock = new PlataformaMock();
    EXPECT_CALL(*plataformaMock, consola(_)).Times(AnyNumber());
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

void dadoQueSePuedeLlamarADemorar(){
    EXPECT_CALL(*plataformaMock, demorar(_)).Times(AnyNumber());
}

void dadoQueSeLlamara3VecesADemoraDe2Milisegundos() {
    EXPECT_CALL(*plataformaMock, demorar(2)).Times(AtLeast(3));
}