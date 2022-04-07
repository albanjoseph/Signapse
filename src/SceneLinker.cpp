#include "SceneLinker.h"

void SceneLinker::RegisterCallback(SceneCallback *scb) {
    sceneCallback = scb;
}

void SceneLinker::NextScene(Scene scene) {
    sceneCallback->NextScene(scene);
}