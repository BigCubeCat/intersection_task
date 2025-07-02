cmake_minimum_required(VERSION 3.10)
project(vector_lib VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(vector_lib STATIC
        src/vector3d.cpp
        src/segment3d.cpp
        include/utils.hpp
        src/utils.cpp
)

target_include_directories(vector_lib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

option(USE_TESTS "enable tests" OFF)

if (USE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
