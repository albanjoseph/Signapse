//
// Created by adam on 09/02/2022.
//

#include "camera.h"
#include "scene.h"
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <thread>
#include "FrameEditor.cpp"


Camera::Camera() {
    isOn=true;
}


void Camera::setOn(bool state){
    isOn = state;
}

void Camera::threadLoop(){
    while(isOn){
        dataReady();
    }
}

void Camera::postFrame(SceneCallback* callback){
    if(!callback) return;
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
    s = FrameEditor::drawBox(s);
    callback->nextScene(s);
}

void Camera::dataReady(){
    postFrame(cnnCallback);
    postFrame(frameCallback);
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
    videoCapture.open(deviceID, apiID);
    printf("starting camera threads \n");
    cameraThread = std::thread(&Camera::threadLoop, this);
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

void Camera::registerCNNCallback(SceneCallback *cnncb) {
    cnnCallback = cnncb;
}

void Camera::registerFrameCallback(SceneCallback *fcb) {
    frameCallback = fcb;
}