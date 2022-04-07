#ifndef SIGNAPSE_SCENELINKSCHEDULER_H
#define SIGNAPSE_SCENELINKSCHEDULER_H

#include "SchedulableSceneLinker.h"

#define DEFAULT_TARGET_FPS 15.0f

class SceneLinkScheduler: SceneLinker{
public:
    void NextScene(Scene s);
    SceneLinkScheduler(SceneLinker* toSchedule, float throughput_fps=DEFAULT_TARGET_FPS);
    void RegisterCallback(SceneCallback* scb);
private:
    SchedulableSceneLinker* toSchedule;
    SceneLinker* outputLink;
    float targetThroughput_fps;
};


#endif //SIGNAPSE_SCENELINKSCHEDULER_H
