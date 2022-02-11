
cmake_minimum_required(VERSION 3.0)
project(Signapse)
add_executable(Signapse ../src/main.cpp)
set_target_properties(Signapse PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./bin/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./lib)

add_library(
        reel
        ../src/reel.h
        ../src/reel.cpp
)
add_library(
        camera
        ../src/camera.h
        ../src/camera.cpp
)
add_library(
        taskmaster
        ../src/taskmaster.h
        ../src/taskmaster.cpp
)
add_library(
        CNNProcessor
        ../src/CNNProcessor.h
        ../src/CNNProcessor.cpp
)

target_link_libraries(Signapse reel camera taskmaster CNNProcessor)

add_compile_options(-Wall)