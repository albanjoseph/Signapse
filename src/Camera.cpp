#include "Camera.h"

/*!
 * Camera default constructor, inits settings, sets isOn to true.
 */
Camera::Camera() : cameraSettings() {
    isOn=true;
}
/*!
 * Camera constructor from settings, sets isOn to true.
 */
Camera::Camera(CameraSettings settings) : cameraSettings(settings){
    isOn = true;
}

/*!
 * Sets the isOn state of the camera
 * @param state
 */
void Camera::setOn(bool state){
    isOn = state;
}

/*!
 * Loops while camera is on to add frames to the pipeline
 */
void Camera::threadLoop(){
    while(isOn){
        postFrame();
    }
}

/*!
 * Gets the next available frame and passes it on to the registered callback. Relies on the videoCapture.read() OpenCV method which is understood to wait for an intra-frame delay.
 */
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

/*!
 * Starts the worker thread recording
 */
void Camera::Start(){
    videoCapture.open(cameraSettings.deviceID, cameraSettings.apiID);
    cameraThread = std::thread(&Camera::threadLoop, this);
}

/*!
 * Frees thread resources and stops recording, must be called prior to program exit.
 */
void Camera::Stop(){
    isOn=false;
    cameraThread.join();

}

/*!
 * Returns the isON state of the camera
 * @return true if on; false otherwise
 */
bool Camera::getOn() {
    return isOn;
}
