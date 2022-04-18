#ifndef SIGNAPSE_SCENELINKER_H
#define SIGNAPSE_SCENELINKER_H

#include "SceneCallback.h"

/*!
 * A simple class which extends SceneCallback to add a RegisterCallback method. Also implements a default NextScene function.
 * This class forms the basis for pipeline elements in the Signapse video processing architecture.
 */
class PipelineLink : public SceneCallback{
public:
    void RegisterCallback(SceneCallback* scb);

protected:
    void NextScene(Scene scene);
    SceneCallback* sceneCallback = nullptr;
};

#endif