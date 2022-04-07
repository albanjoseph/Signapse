#ifndef SIGNAPSE_SCHEDULABLESCENELINKER_H
#define SIGNAPSE_SCHEDULABLESCENELINKER_H

#include "SceneLinkScheduler.h"
#include "SceneLinker.h"

class SchedulableSceneLinker : public SceneLinker{
    void RegisterScheduler(SceneLinkScheduler* sls);
private:
    SceneLinkScheduler* informWhenFinished;
};


#endif //SIGNAPSE_SCHEDULABLESCENELINKER_H
