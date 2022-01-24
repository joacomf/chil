cmake_minimum_required (VERSION 3.10)
project(Chil)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB Chil_FILES src/*.cpp src/*.h src/*.hpp)

add_library(Chil ${Chil_FILES} src/modelo/verificacion/excepciones/ValorNoEsMayorOIgualExcepcion.h src/modelo/verificacion/excepciones/ValorNoEsMenorOIgualExcepcion.h src/modelo/verificacion/excepciones/ValorNoEstaEntreExcepcion.h)

target_include_directories(Chil PRIVATE include)
target_include_directories(Chil PRIVATE src)
target_include_directories(Chil PRIVATE plataformas/modelos)

set_target_properties(Chil PROPERTIES PUBLIC_HEADER src/Chil.h)


if(BUILD_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory (tests)
endif()