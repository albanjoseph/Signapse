cmake_minimum_required(VERSION 3.0)
project(Signapse)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(taskmaster_unit_test taskmaster_test)

set_target_properties(Signapse PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../bin/)
set_target_properties(taskmaster_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ..)
add_compile_options(-Wall)