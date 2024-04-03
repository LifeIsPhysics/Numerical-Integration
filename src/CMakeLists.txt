add_library(Integrator STATIC Integrator.cpp TrapezoidRule.cpp)

target_include_directories(Integrator PUBLIC "${PROJECT_SOURCE_DIR}/include")
