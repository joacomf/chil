cmake_minimum_required (VERSION 3.10)
project(chil)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(chil
        src/Chil.cpp
        src/main.cpp
        src/modelo/Escenario.cpp
        src/modelo/Paso.cpp
        src/utils/stringUtils.cpp
        )

target_include_directories(chil PRIVATE include)
target_include_directories(chil PRIVATE src)
set_target_properties(chil PROPERTIES PUBLIC_HEADER include/Chil.h)

# Uncomment for tests
include(CTest)
enable_testing()

if(BUILD_TESTING)
    add_subdirectory (tests)
endif()