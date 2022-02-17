
cmake_minimum_required(VERSION 3.0)
project(Signapse)
add_executable(Signapse ../src/main.cpp ../src/reel.cpp ../src/camera.cpp ../src/taskmaster.cpp ../src/CNNProcessor.cpp)
set_target_properties(Signapse PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./bin/)

#target_link_libraries(Signapse reel camera taskmaster CNNProcessor)

add_compile_options(-Wall)