cmake_minimum_required(VERSION 3.0)
project(Signapse)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(camera_unit_test camera_test)
add_test(inference_test inference_test)

set_target_properties(Signapse PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../bin/)
set_property(TARGET Signapse PROPERTY AUTOMOC ON)
set_target_properties(camera_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ..)
set_target_properties(inference_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ..)
add_compile_options(-Wall)