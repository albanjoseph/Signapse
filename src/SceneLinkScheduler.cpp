#include "SceneLinkScheduler.h"

SceneLinkScheduler::SceneLinkScheduler(PipelineLink *toSchedule, float throughput_fps) {
    targetThroughput_fps = throughput_fps;
}

void SceneLinkScheduler::RegisterCallback(SceneCallback *scb) {
    sceneCallback = scb;
}

void SceneLinkScheduler::NextScene(Scene s) {
    if(toSchedule->Available()){
        toSchedule->Enqueue(s);
    }
    else{
        sceneCallback->NextScene(s);
    }
    
}
