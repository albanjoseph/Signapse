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
    isOn = true;
    videoCapture.open(deviceID, apiID);
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
    Scene s = Scene{
            .frame=frame,
            .timestamp = 1,
            .task = currentTask,
            .result = {}
    };
    sceneQueue.Push(s);
}

void Camera::start_thread(){
    cameraThread = std::thread(&Camera::Stream, this);
}

void Camera::Stream() {
    while (isOn) {
        Populate();
    }
}

void Camera::set_current_task(char new_task){
    currentTask = new_task;
}