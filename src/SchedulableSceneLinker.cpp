#include "SchedulableSceneLinker.h"
#include "BlockingQueue.cpp"


void SchedulableSceneLinker::Process(){
    while(isOn){
        Scene s = scheduleQueue.Pop(); //Blocking Queue Sleeps Execution Until Scene arrives
        NextScene(s);
    }
}

void SchedulableSceneLinker::Enqueue(Scene s) {
    scheduleQueue.Push(s);
}

bool SchedulableSceneLinker::Available() {
    return scheduleQueue.IsEmpty(); //singly threaded for now
}

void SchedulableSceneLinker::Start() {
    scheduleWorker = std::thread(&SchedulableSceneLinker::Process, this);
}
