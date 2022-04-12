#ifndef SIGNAPSE_DOUBLESCENELINKER_H
#define SIGNAPSE_DOUBLESCENELINKER_H

#include "PipelineLink.h"

class DoubleSceneLinker : public PipelineLink{
public:
    void NextScene(Scene s);
    void RegisterSecondaryCallback(SceneCallback* scb);
public:
    SceneCallback* secondarySceneCallback = nullptr;
    
};


#endif //SIGNAPSE_DOUBLESCENELINKER_H
