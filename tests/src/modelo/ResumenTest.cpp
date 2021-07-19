#include <modelo/Resumen.h>
#include <modelo/Escenario.h>
#include <mocks/PlataformaMock.hpp>
#include "gtest/gtest.h"

TEST(ResumenTest, seRegistranLosEscenariosCompletados) {
    auto* resumen = new Resumen();

    resumen->registrarEscenarioConResultado(true);
    resumen->registrarEscenarioConResultado(false);
    resumen->registrarEscenarioConResultado(false);
    resumen->registrarEscenarioConResultado(true);


    ASSERT_EQ(resumen->escenarioFallidos(), 2);
    ASSERT_EQ(resumen->escenariosExitosos(), 2);
    ASSERT_EQ(resumen->escenarioCompletados(), 4);
}

TEST(ResumenTest, seRegistraUnEscenarioFallido) {
    auto* resumen = new Resumen();
    resumen->registrarEscenarioConResultado(false);

    ASSERT_EQ(resumen->escenarioFallidos(), 1);
    ASSERT_EQ(resumen->escenarioCompletados(), 1);
}

TEST(ResumenTest, seRegistraDosEscenariosExitosos) {
    auto* resumen = new Resumen();
    resumen->registrarEscenarioConResultado(true);

    ASSERT_EQ(resumen->escenariosExitosos(), 1);
    ASSERT_EQ(resumen->escenarioCompletados(), 1);
}
