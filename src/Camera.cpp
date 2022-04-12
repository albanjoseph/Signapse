#include "Camera.h"

Camera::Camera() {
    isOn=true;
}

void Camera::setOn(bool state){
    isOn = state;
}

void Camera::threadLoop(){
    while(isOn){
        postFrame();
    }
}

void Camera::postFrame(){
    if(!sceneCallback) return;
    cv::Mat temp;
    videoCapture.read(temp);
    // check if we succeeded
    if (temp.empty()) {
        std::cerr << "ERROR! blank frame grabbed\n";
        return;
    }
    Scene s;
    s.frame=temp;
    sceneCallback->NextScene(s);
}

void Camera::Start(){
    videoCapture.open(deviceID, apiID);
    cameraThread = std::thread(&Camera::threadLoop, this);
}

void Camera::Stop(){
    isOn=false;
    if(cameraThread.joinable()){
        cameraThread.join();
    }
}

bool Camera::getOn() {
    return isOn;
}

Camera::~Camera() {
    Stop();
}
