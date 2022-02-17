//
// Created by adam on 09/02/2022.
//

#ifndef SIGNAPSE_CAMERA_H
#define SIGNAPSE_CAMERA_H
#include "reel.h"
#include <opencv2/videoio.hpp>
#include <thread>


class Camera: public Reel{
public:
    Camera();
    void Populate();
    void set_current_task(char new_task);
    void start_thread();

private:
    void Stream();
    char currentTask;
    cv::VideoCapture videoCapture;
    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API
    std::thread cameraThread;
    bool isOn = true;
};


#endif //SIGNAPSE_CAMERA_H
