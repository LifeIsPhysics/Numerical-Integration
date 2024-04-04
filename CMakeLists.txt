cmake_minimum_required(VERSION 3.20...3.29)

project(NumericalIntegrator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -pg")

add_executable(NumericalIntegrator main.cpp)
target_link_libraries(NumericalIntegrator PUBLIC Integrator)

add_subdirectory(src)
add_subdirectory(tests)

target_include_directories(NumericalIntegrator
                           PUBLIC "${PROJECT_SOURCE_DIR}/src")
