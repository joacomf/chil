#include <modelo/Resumen.h>
#include <modelo/Escenario.h>
#include <mocks/PlataformaMock.hpp>
#include "gtest/gtest.h"

TEST(ResumenTest, seRegistranLosEscenariosCompletados) {
    auto* resumen = new Resumen();
    resumen->registrarEscenarioConResultado(true);

    ASSERT_EQ(resumen->escenarioCompletados(), 1);
}
