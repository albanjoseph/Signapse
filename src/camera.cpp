//
// Created by adam on 09/02/2022.
//

#include "camera.h"
#include "scene.h"
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <thread>


Camera::Camera() {
    videoCapture.open(deviceID, apiID);
}

void Camera::on(bool state){
    isOn = state;
}


void Camera::Populate(){
    cv::Mat temp;
    videoCapture.read(temp);
    // check if we succeeded
    if (temp.empty()) {
        std::cerr << "ERROR! blank frame grabbed\n";
    }
    cv::Mat frame;
    cv::flip(temp, frame, 1);
    cv::Size sz = frame.size();
    Scene s = Scene{
            .frame=frame,
            .timestamp = 1,
            .task = currentTask,
            .result = {},
            .regionOfInterest = {(int)(sz.width * boundingBox[0]),
                                 (int)(sz.height * boundingBox[1]),
                                 (int)(sz.width * boundingBox[2]),
                                 (int)(sz.height * boundingBox[3])}
    };
    sceneQueue.Push(s);
}

void Camera::start_thread(){
    cameraThread = std::thread(&Camera::Stream, this);
}

void Camera::Stream() {
    while (1) {
        if(isOn){
            Populate();
        }
    }
}

void Camera::set_current_task(char new_task){
    currentTask = new_task;
}

void Camera ::setBoundingBox(float upperLeftX, float upperLeftY, float lowerRightX, float lowerRightY) {
    boundingBox[0] = upperLeftX;
    boundingBox[1] = upperLeftY;
    boundingBox[2] = lowerRightX;
    boundingBox[3] = lowerRightY;
}