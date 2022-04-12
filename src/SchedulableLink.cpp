#include "SchedulableLink.h"
#include "BlockingQueue.cpp"


void SchedulableLink::Run(){
    //waits for scenes to appear on the scheduleQueue,
    while(isOn){
        Scene s = scheduleQueue.Pop(); //Blocking Queue Sleeps Execution Until Scene arrives
        Scene out = ProcessScene(s);
        if(!sceneCallback) continue;
        sceneCallback->NextScene(out);
    }
}

void SchedulableLink::Enqueue(Scene s) {
    scheduleQueue.Push(s);
}

bool SchedulableLink::Available() {
    return scheduleQueue.IsEmpty(); //singly threaded for now
}

void SchedulableLink::Start() {
    scheduleWorker = std::thread(&SchedulableLink::Run, this);
}

void SchedulableLink::NextScene(Scene scene) {
    //if space on schedule queue, add this scene; otherwise pass the scene through
    if(scheduleQueue.IsEmpty()) { //singly threaded for now
        scheduleQueue.Push(scene);
    }
    
}