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
        src/modelo/verificacion/VerificacionIgualesTest.cpp
        src/modelo/verificacion/VerificacionEnBucleTest.cpp
        src/modelo/verificacion/VerificacionMayorYMenorTest.cpp
        src/modelo/verificacion/VerificacionEntreTest.cpp
        src/modelo/exportador/ExportadorJSONTest.cpp

        plataformas/interfaces/PuntoDeEntradaTest.cpp

        ../src/Chil.h
        ../src/Chil.cpp
        ../src/macros.h
        ../src/macros.cpp

        ../src/modelo/Paso.h
        ../src/modelo/Paso.cpp
        ../src/modelo/Escenario.h
        ../src/modelo/Escenario.cpp
        ../src/modelo/Resumen.h
        ../src/modelo/Resumen.cpp

        ../src/utilidades/literales.h
        ../src/utilidades/literales.cpp

        ../src/modelo/verificacion/Verificacion.h
        ../src/modelo/verificacion/Verificacion.cpp
        ../src/modelo/verificacion/valores/AccionVerificable.h
        ../src/modelo/verificacion/valores/AccionVerificable.cpp
        ../src/modelo/verificacion/valores/ValorVerificable.h
        ../src/modelo/verificacion/valores/ValorVerificable.cpp
        ../src/modelo/verificacion/excepciones/ValorNoEsMenorExcepcion.h
        ../src/modelo/verificacion/excepciones/ValorNoEsMayorExcepcion.h

        ../src/modelo/ejecutores/Ejecutor.h
        ../src/modelo/ejecutores/EjecutorSimple.cpp
        ../src/modelo/ejecutores/EjecutorSimple.h
        ../src/modelo/ejecutores/EjecutorConManejoDeErrores.cpp
        ../src/modelo/ejecutores/EjecutorConManejoDeErrores.h

        ../src/utilidades/exportador/ExportadorJSON.cpp
        ../src/utilidades/exportador/ExportadorJSON.h
        )

add_test(NAME check COMMAND tests)

target_include_directories (
        tests
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../src
        ${CMAKE_CURRENT_SOURCE_DIR}/../plataformas/interfaces
)

# Link Libreria Google Test
target_link_libraries(tests gmock_main)