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
    cv::Mat cap;
    videoCapture.read(cap);
    // check if we succeeded
    if (cap.empty()) {
        std::cerr << "ERROR! blank frame grabbed\n";
        return;
    }
    Scene s;
    s.frame=cap;
    sceneCallback->NextScene(s);
}

void Camera::Start(){
    videoCapture.open(deviceID, apiID);
    cameraThread = std::thread(&Camera::threadLoop, this);
}

void Camera::Stop(){
    isOn=false;
    cameraThread.join();

}

bool Camera::getOn() {
    return isOn;
}

Camera::~Camera() {
    //Stop();
}
