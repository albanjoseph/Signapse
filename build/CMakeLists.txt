
cmake_minimum_required(VERSION 3.0)
project(Signapse)
add_executable(Signapse ../src/main.cpp)
set_target_properties(Signapse PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./bin/)

add_library(
        reel
        ../src/reel.h
        ../src/reel.cpp
)
#add_library(
#        Opt
#        ../src/Option.hpp
#        ../src/Option.cpp
#)

target_link_libraries(Signapse reel)

add_compile_options(-Wall)