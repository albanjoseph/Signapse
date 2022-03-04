cmake_minimum_required(VERSION 3.0)
project(Signapse)

set(OpenCV_DIR "${CMAKE_CURRENT_BINARY_DIR}/opencv_build")
message("Linking OpenCV build at directory: " ${OpenCV_DIR}$ )
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
message("Including OpenCV build at directory: " ${OpenCV_INCLUDE_DIRS})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

add_executable(Signapse ../src/main.cpp ../src/reel.cpp ../src/camera.cpp ../src/taskmaster.cpp ../src/CNNProcessor.cpp ../src/BlockingQueue.cpp)
set_target_properties(Signapse PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./bin/)

target_link_libraries(Signapse ${OpenCV_LIBS} )

add_compile_options(-Wall)