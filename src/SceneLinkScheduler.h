#ifndef SIGNAPSE_SCENELINKSCHEDULER_H
#define SIGNAPSE_SCENELINKSCHEDULER_H

#include "SchedulableSceneLinker.h"
#include "scene.h"

#define DEFAULT_TARGET_FPS 15.0f

class SceneLinkScheduler : public SceneLinker{
public:
    void NextScene(Scene s);
    SceneLinkScheduler(SceneLinker* toSchedule, float throughput_fps=DEFAULT_TARGET_FPS);
    void RegisterCallback(SceneCallback* scb);
private:
    SchedulableSceneLinker* toSchedule;
    float targetThroughput_fps;
};


#endif //SIGNAPSE_SCENELINKSCHEDULER_H
