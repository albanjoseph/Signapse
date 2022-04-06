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
    cv::Mat frame_bgr;
    cv::Mat frame;
    cv::flip(temp, frame_bgr, 1);
    cv::cvtColor(frame_bgr, frame, cv::COLOR_BGR2RGB);
    cv::Size sz = frame.size();

    Scene s = Scene{
            .frame=frame,
            .timestamp = 1,
            .result = {},
            .regionOfInterest = {(int)(sz.width * boundingBox[0]),
                                 (int)(sz.height * boundingBox[1]),
                                 (int)(sz.width * boundingBox[2]),
                                 (int)(sz.height * boundingBox[3])}
    };
    s = FrameEditor::drawBox(s);
    callback->NextScene(s);
}

void Camera::dataReady(){
    postFrame(cnnCallback);
    postFrame(frameCallback);
}

void Camera::Populate(){
    cv::Mat frame;
    videoCapture.read(frame);
    // check if we succeeded
    if (frame.empty()) {
        std::cerr << "ERROR! blank frame grabbed\n";
    }
    cv::Size sz = frame.size();
    Scene s = Scene{
            .frame=frame,
            .timestamp = 1,
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
    cameraThread = std::thread(&Camera::threadLoop, this);
}

void Camera::Stream() {
    while (1) {
        if(isOn){
            Populate();
        }
    }
}

float* Camera::getBoundingBox() {

    return boundingBox;
}

bool Camera::getOn() {
    return isOn;
}

void Camera ::setBoundingBox(float upperLeftX, float upperLeftY, float lowerRightX, float lowerRightY) {
    boundingBox[0] = upperLeftX;
    boundingBox[1] = upperLeftY;
    boundingBox[2] = lowerRightX;
    boundingBox[3] = lowerRightY;
    for(int i = 0; i < 4; i++){
        float val = boundingBox[i];
        if(val > 1.0f){
            boundingBox[i] = 1.0f;
        }
        else if (val < 0.0f){
            boundingBox[i] = 0.0f;
        }
    }
}

void Camera::registerCNNCallback(SceneCallback *cnncb) {
    cnnCallback = cnncb;
}

void Camera::registerFrameCallback(SceneCallback *fcb) {
    frameCallback = fcb;
}