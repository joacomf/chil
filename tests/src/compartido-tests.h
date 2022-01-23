#ifndef CHIL_COMPARTIDO_TESTS_H
#define CHIL_COMPARTIDO_TESTS_H

#include <climits>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mocks/PlataformaMock.hpp"

#include "Chil.h"

#include "modelo/verificacion/excepciones/AccionNoEjecutadaExcepcion.h"
#include "modelo/verificacion/Verificacion.h"

using ::testing::AtLeast;
using ::testing::Exactly;
using ::testing::_;
using ::testing::Return;
using ::testing::Test;

#endif //CHIL_COMPARTIDO_TESTS_H
