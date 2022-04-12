#ifndef SIGNAPSE_SCENELINKSCHEDULER_H
#define SIGNAPSE_SCENELINKSCHEDULER_H

#include "SchedulableLink.h"
#include "Scene.h"

#define DEFAULT_TARGET_FPS 15.0f

class SceneLinkScheduler : public PipelineLink{
public:
    void NextScene(Scene s);
    SceneLinkScheduler(PipelineLink* toSchedule, float throughput_fps=DEFAULT_TARGET_FPS);
    void RegisterCallback(SceneCallback* scb);
private:
    SchedulableLink* toSchedule;
    float targetThroughput_fps;
};


#endif //SIGNAPSE_SCENELINKSCHEDULER_H
