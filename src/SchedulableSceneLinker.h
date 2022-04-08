#ifndef SIGNAPSE_SCHEDULABLESCENELINKER_H
#define SIGNAPSE_SCHEDULABLESCENELINKER_H

#include <thread>

#include "SceneLinker.h"
#include "BlockingQueue.h"



class SchedulableSceneLinker : public SceneLinker{
public:
    void Start();
    void Enqueue(Scene s);
    bool Available();
private:
    void Process();
    BlockingQueue<Scene> scheduleQueue;
    bool isOn = true;
    std::thread scheduleWorker;
    
};


#endif //SIGNAPSE_SCHEDULABLESCENELINKER_H
