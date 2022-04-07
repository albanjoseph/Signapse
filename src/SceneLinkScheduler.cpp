#include "SceneLinkScheduler.h"

SceneLinkScheduler::SceneLinkScheduler(SceneLinker *toSchedule, float throughput_fps) {
    sceneCallback = outputLink;
    toSchedule->RegisterCallback(outputLink);
    targetThroughput_fps = throughput_fps;
}

void SceneLinkScheduler::RegisterCallback(SceneCallback *scb) {
    outputLink->RegisterCallback(scb);
}

void SceneLinkScheduler::NextScene(Scene s) {

}

void SceneLinkScheduler::NotifyFinished(){

}