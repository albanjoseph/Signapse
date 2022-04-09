#ifndef SIGNAPSE_DOUBLESCENELINKER_H
#define SIGNAPSE_DOUBLESCENELINKER_H

#include "SceneLinker.h"

class DoubleSceneLinker : public SceneLinker{
public:
    void NextScene(Scene s);
    void RegisterSecondaryCallback(SceneCallback* scb);
public:
    SceneCallback* secondarySceneCallback = nullptr;
    
};


#endif //SIGNAPSE_DOUBLESCENELINKER_H
