set(OpenCV_DIR "${CMAKE_CURRENT_BINARY_DIR}/opencv_build")
message("Linking OpenCV build at directory: " ${OpenCV_DIR}$ )
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
message("Including OpenCV build at directory: " ${OpenCV_INCLUDE_DIRS})

add_executable(Signapse main.cpp reel.cpp camera.cpp taskmaster.cpp CNNProcessor.cpp BlockingQueue.cpp)
target_link_libraries(Signapse ${OpenCV_LIBS})

add_library(taskmaster taskmaster.cpp taskmaster.h)

add_library(reel reel.cpp reel.h)
target_link_libraries(reel ${OpenCV_LIBS})

add_library(camera camera.cpp camera.h)
target_link_libraries(camera ${OpenCV_LIBS} reel)