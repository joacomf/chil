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

        ../src/modelo/Paso.cpp
        ../src/modelo/Acciones.cpp
        ../src/utils/stringUtils.cpp
        src/modelo/AccionesTest.cpp)

add_test(NAME check COMMAND tests)

target_include_directories (
        tests
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

# Link Libreria Google Test
target_link_libraries(tests gmock_main)