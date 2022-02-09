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
            .task = currentTask,
            .result = {}
    };
    frameQueue.push(s);
}


void Camera::set_current_task(char new_task){
    currentTask = new_task;
}