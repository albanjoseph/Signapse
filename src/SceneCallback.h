#ifndef SIGNAPSE_SCENECALLBACK_H
#define SIGNAPSE_SCENECALLBACK_H

#include "Scene.h"
/*!
 * A simple callback interface for passing Scenes through the pipeline
 */
class SceneCallback{
public:
    virtual void NextScene(Scene next) = 0;
};

#endif