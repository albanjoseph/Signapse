set(OpenCV_DIR "../opencv_build")
message("Linking OpenCV build at directory: " ${OpenCV_DIR}$ )
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
message("Including OpenCV build at directory: " ${OpenCV_INCLUDE_DIRS})

find_package(Qt5Widgets REQUIRED)

add_executable(Signapse main.cpp reel.cpp Camera.cpp CNNProcessor.cpp PipelineLink.cpp SceneLinkScheduler.cpp LinkSplitter.cpp NThreadedCNNProcessor.cpp SchedulableLink.cpp MultiThreadedSchedulableLink.cpp BatchCNNProcessor.cpp PreProcessor.cpp BlockingQueue.cpp Gui.cpp ProgressBar.cpp )
target_link_libraries(Signapse ${OpenCV_LIBS} Qt5::Widgets)


add_library(reel reel.cpp reel.h)
target_link_libraries(reel ${OpenCV_LIBS})

add_library(Camera Camera.cpp Camera.h)
target_link_libraries(Camera ${OpenCV_LIBS} reel)

add_library(CNNProcessor CNNProcessor.cpp CNNProcessor.h MultiThreadedSchedulableLink.cpp SchedulableLink.cpp PipelineLink.cpp)
target_link_libraries(CNNProcessor ${OpenCV_LIBS})

add_library(PreProcessor PreProcessor.cpp PreProcessor.h)
target_link_libraries(PreProcessor ${OpenCV_LIBS})

add_library(Gui Gui.cpp Gui.h)
target_link_libraries(Gui ${OpenCV_LIBS} Qt5::Widgets)