#include "camera.h"



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

void Camera::postFrame(){
    if(!sceneCallback) return;
    cv::Mat temp;
    videoCapture.read(temp);
    // check if we succeeded
    if (temp.empty()) {
        std::cerr << "ERROR! blank frame grabbed\n";
    }
    Scene s;
    s.frame=temp;
    sceneCallback->NextScene(s);
}

void Camera::dataReady(){
    postFrame();
}

void Camera::start_thread(){
    videoCapture.open(deviceID, apiID);
    cameraThread = std::thread(&Camera::threadLoop, this);
}


bool Camera::getOn() {
    return isOn;
}
