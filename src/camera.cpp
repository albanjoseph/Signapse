//
// Created by adam on 09/02/2022.
//

#include "camera.h"
#include "scene.h"
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>


void Camera::Stream(){
    while(true){
        Populate();
    }
}

void Camera::Populate(){
    videoCapture.open(deviceID, apiID); // move to constructor
    cv::Mat frame;
    videoCapture.read(frame);
    // check if we succeeded
    if (frame.empty()) {
        std::cerr << "ERROR! blank frame grabbed\n";
    }

    Scene s = Scene{
            .frame=frame,
            .timestamp = 1,
            .task = currentTask,
            .result = {}
    };
    frameQueue.push(s);
}


void Camera::set_current_task(char new_task){
    currentTask = new_task;
}