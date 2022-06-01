cmake_minimum_required (VERSION 3.10)
project(tests)

add_definitions(-fprofile-arcs -ftest-coverage)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fprofile-arcs -ftest-coverage")

set(OBJECT_DIR ${CMAKE_BINARY_DIR}/tests/CMakeFiles/tests.dir/src)
message("-- Los archivos de objeto serán enviados a: ${OBJECT_DIR}")

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

        src/interfaces/PuntoDeEntradaTest.cpp

        ../src/Chil.h
        ../src/Chil.cpp
        ../src/macros.h
        ../src/macros.cpp

        ../src/interfaces/Plataforma.h
        ../src/interfaces/PuntoDeEntrada.h
        ../src/interfaces/PuntoDeEntrada.cpp

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

target_include_directories (
        tests
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

# Construir la libreria de GoogleTest
add_subdirectory(vendor)

add_custom_target(init
        COMMAND ${CMAKE_MAKE_PROGRAM} clean
        COMMAND rm -f ${OBJECT_DIR}/*.gcno
        COMMAND rm -f ${OBJECT_DIR}/*.gcda
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )

add_custom_target(gcov
        COMMAND mkdir -p gcoverage
        COMMAND tests check
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )

add_custom_command(TARGET gcov
        COMMAND echo "=================== GCOV ===================="
        COMMAND echo "Directorio objetos ${OBJECT_DIR}"
        COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/ -o ${OBJECT_DIR}/*
        COMMAND echo "-- Directorio fuente: ${CMAKE_SOURCE_DIR}/src/"
        COMMAND echo "-- Los archivos de cobertura estan en ${CMAKE_BINARY_DIR}/gcoverage"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gcoverage
        )
add_dependencies(gcov tests)

add_custom_target(lcov
        COMMAND mkdir -p lcoverage
        )
add_custom_command(TARGET lcov
        COMMAND echo "=================== LCOV ===================="
        COMMAND echo "-- Ejecutando lcov sobre los archivos de cobertura"
        COMMAND lcov --capture --directory . --output-file coverage.info
        COMMAND lcov --remove coverage.info "*/include/*" --remove coverage.info "*/_deps/*" --remove coverage.info "*/tests/*" --output-file coverage.info
        COMMAND lcov --list coverage.info
        )

add_custom_target(reporte
        COMMAND echo "-- Generando archivo HTML"
        COMMAND genhtml coverage.info --output-directory lcoverage
        )

add_test(output_test ${CMAKE_CURRENT_BINARY_DIR}/tests)

# Make sure to clean up the coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES gcoverage)

enable_testing()

add_test(NAME check COMMAND tests)

target_link_libraries(tests gtest)
target_link_libraries(tests gmock)
target_link_libraries(tests -fprofile-arcs)
