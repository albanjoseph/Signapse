//
// Created by ross on 07/04/2022.
//

#include "SchedulableSceneLinker.h"

void SchedulableSceneLinker::RegisterCallback(SceneCallback *scb) {
    informWhenFinished = scb;
}