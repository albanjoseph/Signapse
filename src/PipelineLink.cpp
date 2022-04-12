#include "PipelineLink.h"

void PipelineLink::RegisterCallback(SceneCallback *scb) {
    sceneCallback = scb;
}

void PipelineLink::NextScene(Scene scene) {
    if(!sceneCallback) return;
    sceneCallback->NextScene(scene);
}