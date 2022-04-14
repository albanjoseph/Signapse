#include "SchedulableLink.h"
#include "BlockingQueue.cpp"


/*!
 * Looping process to process scenes and call-back to next pipeline element. Worker thread is slept while no elements are available using BlockingQueue functionality
 */
void SchedulableLink::Run(){
    //waits for scenes to appear on the scheduleQueue,
    while(isOn){
        Scene s = scheduleQueue.Pop(); //Blocking Queue Sleeps Execution Until Scene arrives
        Scene out = ProcessScene(s);
        if(!sceneCallback) continue;
        sceneCallback->NextScene(out);
    }
}
/*!
 * Adds a scene to the intenal scheduleQueue
 * @param s
 */
void SchedulableLink::Enqueue(Scene s) {
    scheduleQueue.Push(s);
}
/*!
 * @return true if the scheduleQueue is empty; false otherwise.
 */
bool SchedulableLink::Available() {
    return scheduleQueue.IsEmpty(); //singly threaded for now
}

/*!
 * Starts execution with the worker thread.
 */
void SchedulableLink::Start() {
    scheduleWorker = std::thread(&SchedulableLink::Run, this);
}
/*!
 * Turns off the link, kills worker thread. Must be called to release thread resources.
 */
void SchedulableLink::Stop(){
    isOn = false;
    scheduleWorker.join();
}
/*!
 * If space is available on the scheduleQueue, add the scene to the queue. Otherwise skip.
 * @param scene
 */
void SchedulableLink::NextScene(Scene scene) {
    //if space on schedule queue, add this scene; otherwise pass the scene through
    if(scheduleQueue.IsEmpty()) { //singly threaded for now
        scheduleQueue.Push(scene);
    }
}

