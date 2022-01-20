#include "gtest/gtest.h"
#include "modelo/verificacion/Verificacion.h"

TEST(VerificacionTest, verificaUnValorEnteroCorrectamente) {
    ASSERT_NO_THROW(verificar(5).esIgualA(5));
}
