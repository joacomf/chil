cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Construir la libreria de GoogleTest
add_subdirectory(vendor)

add_executable(
        tests

        src/tests.cpp
        src/ChilTest.cpp
        src/modelo/EscenarioTest.cpp
        src/modelo/PasoTest.cpp
        src/modelo/ResumenTest.cpp
        src/modelo/verificacion/VerificacionTest.cpp
        src/modelo/verificacion/VerificacionEnBucleTest.cpp

        ../src/Chil.h
        ../src/Chil.cpp

        ../src/macros.h
        ../src/macros.cpp

        ../src/modelo/Paso.h
        ../src/modelo/Escenario.h
        ../src/modelo/Resumen.h
        ../src/utils/stringUtils.h
        ../src/utils/literales.h

        ../src/modelo/Paso.cpp
        ../src/modelo/Escenario.cpp
        ../src/modelo/Resumen.cpp
        ../src/utils/stringUtils.cpp
        ../src/utils/literales.cpp

        ../src/modelo/verificacion/Verificacion.h
        ../src/modelo/verificacion/Verificacion.cpp
        ../src/modelo/verificacion/valores/AccionVerificable.h
        ../src/modelo/verificacion/valores/AccionVerificable.cpp
        ../src/modelo/verificacion/valores/ValorVerificable.h


        plataformas/modelo/PuntoDeEntradaTest.cpp
)

add_test(NAME check COMMAND tests)

target_include_directories (
        tests
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../src
        ${CMAKE_CURRENT_SOURCE_DIR}/../plataformas/modelos
)

# Link Libreria Google Test
target_link_libraries(tests gmock_main)