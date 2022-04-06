set(OpenCV_DIR "../opencv_build")
message("Linking OpenCV build at directory: " ${OpenCV_DIR}$ )
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
message("Including OpenCV build at directory: " ${OpenCV_INCLUDE_DIRS})

find_package(Qt5Widgets REQUIRED)

add_executable(Signapse main.cpp reel.cpp camera.cpp taskmaster.cpp CNNProcessor.cpp SceneProcessor.cpp BlockingQueue.cpp Gui.cpp ProgressBar.cpp )
target_link_libraries(Signapse ${OpenCV_LIBS} Qt5::Widgets)

add_library(reel reel.cpp reel.h)
target_link_libraries(reel ${OpenCV_LIBS})

add_library(camera camera.cpp camera.h)
target_link_libraries(camera ${OpenCV_LIBS} reel)

add_library(CNNProcessor CNNProcessor.cpp CNNProcessor.h SceneProcessor.cpp)
target_link_libraries(CNNProcessor ${OpenCV_LIBS})

add_library(FrameEditor FrameEditor.cpp FrameEditor.h)
target_link_libraries(FrameEditor ${OpenCV_LIBS})

add_library(Gui Gui.cpp Gui.h)
target_link_libraries(Gui ${OpenCV_LIBS} Qt5::Widgets)