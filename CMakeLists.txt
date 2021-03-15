cmake_minimum_required (VERSION 3.10)
project(chil)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(
        chil
        src/Chil.cpp
        src/main.cpp src/Escenario.cpp include/Escenario.h)

target_include_directories (
        chil
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Uncomment for tests
include(CTest)
enable_testing()

if(BUILD_TESTING)
    add_subdirectory (tests)
endif()