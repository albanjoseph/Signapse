#ifndef SIGNAPSE_SCENECALLBACK_H
#define SIGNAPSE_SCENECALLBACK_H

#include "scene.h"

class SceneCallback{
public:
    virtual void NextScene(Scene next) = 0;
};

#endif