#ifndef SIGNAPSE_SCENELINKER_H
#define SIGNAPSE_SCENELINKER_H

#include "SceneCallback.h"

class PipelineLink : public SceneCallback{
public:
    void RegisterCallback(SceneCallback* scb);

protected:
    void NextScene(Scene scene);
    SceneCallback* sceneCallback = nullptr;
};

#endif