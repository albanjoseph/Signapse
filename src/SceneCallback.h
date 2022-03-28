//
// Created by ross on 28/03/2022.
//

#ifndef SIGNAPSE_SCENECALLBACK_H
#define SIGNAPSE_SCENECALLBACK_H
#include "scene.h"

class SceneCallback{
public:
    virtual void nextScene(Scene next) = 0;
};

#endif //SIGNAPSE_SCENECALLBACK_H
