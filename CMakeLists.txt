cmake_minimum_required (VERSION 3.10)
project(Chil)

file (STRINGS "version" NUMERO_VERSION)
message("Chil v${NUMERO_VERSION}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB Chil_FILES src/*.cpp src/*.h src/*.hpp)

add_library(Chil ${Chil_FILES})

target_include_directories(Chil PRIVATE include)
target_include_directories(Chil PRIVATE src)

set_target_properties(Chil PROPERTIES PUBLIC_HEADER src/Chil.h)

if(BUILD_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory (tests)
endif()