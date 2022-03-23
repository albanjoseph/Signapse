add_executable(camera_test camera_test.cpp)
target_include_directories(camera_test PRIVATE ../src)
target_link_libraries(camera_test camera)

set(OpenCV_DIR "../opencv_build")
message("Linking OpenCV build at directory: " ${OpenCV_DIR}$ )
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
message("Including OpenCV build at directory: " ${OpenCV_INCLUDE_DIRS})

add_executable(inference_test inference_test.cpp)
target_include_directories(inference_test PRIVATE ../src)
target_link_libraries(inference_test ${OpenCV_LIBS} CNNProcessor camera)