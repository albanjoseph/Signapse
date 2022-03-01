add_executable(Signapse main.cpp reel.cpp camera.cpp taskmaster.cpp CNNProcessor.cpp BlockingQueue.cpp)
add_library(taskmaster taskmaster.cpp taskmaster.h)
find_package( OpenCV REQUIRED )
target_link_libraries(Signapse ${OpenCV_LIBS})