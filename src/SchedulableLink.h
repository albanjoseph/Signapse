#ifndef SIGNAPSE_SCHEDULABLESCENELINKER_H
#define SIGNAPSE_SCHEDULABLESCENELINKER_H

#include <thread>
#include <chrono>
#include <ctime>

#include "PipelineLink.h"
#include "BlockingQueue.h"



class SchedulableLink : public PipelineLink{
public:
    void NextScene(Scene s);
    virtual Scene ProcessScene(Scene s) = 0;
    void Start();
    void Enqueue(Scene s);
    bool Available();
protected:
    void Run();
    BlockingQueue<Scene> scheduleQueue;
    bool isOn = true;
    std::thread scheduleWorker;
};


#endif //SIGNAPSE_SCHEDULABLESCENELINKER_H
