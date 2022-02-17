//
// Created by adam on 09/02/2022.
//

#ifndef SIGNAPSE_CAMERA_H
#define SIGNAPSE_CAMERA_H
#include "reel.h"
#include <opencv2/videoio.hpp>


class Camera: public Reel{
public:
    void Stream(); //Run in thread
    void Populate(); //Test feature
    void set_current_task(char new_task);
private:
    char currentTask;
    cv::VideoCapture videoCapture;
    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API
};


#endif //SIGNAPSE_CAMERA_H
