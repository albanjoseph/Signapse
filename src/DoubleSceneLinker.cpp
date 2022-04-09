//
// Created by ross on 09/04/2022.
//

#include "DoubleSceneLinker.h"


void DoubleSceneLinker::NextScene(Scene s) {
    if(sceneCallback) sceneCallback->NextScene(s);
    if(secondarySceneCallback) secondarySceneCallback->NextScene(s);
}

void DoubleSceneLinker::RegisterSecondaryCallback(SceneCallback *scb) {
    secondarySceneCallback = scb;
}