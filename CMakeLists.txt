cmake_minimum_required(VERSION 3.20...3.25)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(NumericalIntegrator LANGUAGES CXX)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)
