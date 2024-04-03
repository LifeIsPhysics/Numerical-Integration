cmake_minimum_required(VERSION 3.20...3.25)

project(NumericalIntegrator LANGUAGES CXX)

enable_testing()
add_test(NAME Test COMMAND Test)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(NumericalIntegrator main.cpp)
target_link_libraries(NumericalIntegrator PUBLIC Integrator)

add_subdirectory(src)
add_subdirectory(tests)

target_include_directories(NumericalIntegrator
                           PUBLIC "${PROJECT_SOURCE_DIR}/src")
