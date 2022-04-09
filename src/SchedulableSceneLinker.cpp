#include "SchedulableSceneLinker.h"
#include "BlockingQueue.cpp"


void SchedulableSceneLinker::Run(){
    //waits for scenes to appear on the scheduleQueue,
    while(isOn){
        Scene s = scheduleQueue.Pop(); //Blocking Queue Sleeps Execution Until Scene arrives
        Scene out = ProcessScene(s);
        if(!sceneCallback) continue;
        sceneCallback->NextScene(out);
    }
}

void SchedulableSceneLinker::Enqueue(Scene s) {
    scheduleQueue.Push(s);
}

bool SchedulableSceneLinker::Available() {
    return scheduleQueue.IsEmpty(); //singly threaded for now
}

void SchedulableSceneLinker::Start() {
    scheduleWorker = std::thread(&SchedulableSceneLinker::Run, this);
}

void SchedulableSceneLinker::NextScene(Scene scene) {
    //if space on schedule queue, add this scene; otherwise pass the scene through
    if(scheduleQueue.IsEmpty()) { //singly threaded for now
        scheduleQueue.Push(scene);
    }
    else{
        if(!sceneCallback) return;
        sceneCallback->NextScene(scene);
    }
}