cmake_minimum_required(VERSION 3.0)
SET("OpenCV_DIR" "./opencv_build")
project(Signapse)

SET("OpenCV_DIR" "/usr/share/opencv4")
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(Signapse ../src/main.cpp ../src/reel.cpp ../src/camera.cpp ../src/taskmaster.cpp ../src/CNNProcessor.cpp)
set_target_properties(Signapse PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./bin/)

target_link_libraries(Signapse ${OpenCV_LIBS} )
add_compile_options(-Wall)