#include "LinkSplitter.h"


void LinkSplitter::NextScene(Scene s) {
    if(sceneCallback) sceneCallback->NextScene(s);
    if(secondarySceneCallback) secondarySceneCallback->NextScene(s);
}

void LinkSplitter::RegisterSecondaryCallback(SceneCallback *scb) {
    secondarySceneCallback = scb;
}