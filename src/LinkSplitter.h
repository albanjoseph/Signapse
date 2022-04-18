#ifndef SIGNAPSE_DOUBLESCENELINKER_H
#define SIGNAPSE_DOUBLESCENELINKER_H

#include "PipelineLink.h"

/*!
 * A pipeline element which extends PipelineLink to add a secondary callback. The NextScene function is overridden to pass on the scene reference to both registered callbacks.
 * N.B. this does not duplicate the scene, merely copies the reference to another element. No extra memory is allocated!
 */
class LinkSplitter : public PipelineLink{
public:
    void NextScene(Scene s);
    void RegisterSecondaryCallback(SceneCallback* scb);
public:
    SceneCallback* secondarySceneCallback = nullptr;
    
};


#endif //SIGNAPSE_DOUBLESCENELINKER_H
