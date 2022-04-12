cmake_minimum_required(VERSION 3.0)
project(Signapse)
set(OpenCV_DIR "../opencv_build")
find_package(OpenCV REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(GTest REQUIRED)

include_directories(../src)

enable_testing()

add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS} Qt5::Widgets gtest gtest_main Camera CNNProcessor BlockingQueue)
