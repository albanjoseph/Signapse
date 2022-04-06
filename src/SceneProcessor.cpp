//
// Created by ross on 06/04/2022.
//

#include "SceneProcessor.h"

void SceneProcessor::RegisterCallback(SceneCallback *scb) {
    sceneCallback = scb;
}

void SceneProcessor::NextScene(Scene scene) {
    sceneCallback->NextScene(scene);
}