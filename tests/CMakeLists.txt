add_executable(Test tests.cpp)
target_link_libraries(Test Integrator)
target_include_directories(Test PUBLIC "${PROJECT_SOURCE_DIR}/include"
                                       "${PROJECT_SOURCE_DIR}/src")
