//
// Created by adam on 09/02/2022.
//

#include "camera.h"
#include "scene.h"

void Camera::Stream(){

}
void Camera::Populate(){
    Scene s = Scene{
            .data = {},
            .timestamp = 1,
            .task = 'p',
            .result = {}
    };
    frameQueue.push(s);
}