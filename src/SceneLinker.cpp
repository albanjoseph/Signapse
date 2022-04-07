#include "SceneLinker.h"

void SceneLinker::RegisterCallback(SceneCallback *scb) {
    sceneCallback = scb;
}

void SceneLinker::NextScene(Scene scene) {
    if(!sceneCallback) return;
    sceneCallback->NextScene(scene);
}