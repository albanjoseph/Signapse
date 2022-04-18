#ifndef SIGNAPSE_SCHEDULABLESCENELINKER_H
#define SIGNAPSE_SCHEDULABLESCENELINKER_H

#include <thread>
#include <chrono>
#include <ctime>

#include "PipelineLink.h"
#include "BlockingQueue.h"


/*!
 * A class which extends PipelineLink to handle latency-bound stages.
 * The NextScene function is inherited to add Scenes to an internal BlockingQueue. The pure virtual function ProcessScene must be implemented by derived classes to define Scene processing behaviour. The Run method is called in a separate thread and handles waking up the thread when scenes are available and calling back to the next pipeline element.
 * BlockingQueue is used as a scheduling mechanism for future extension to multithreading.
 */
class SchedulableLink : public PipelineLink{
public:
    void NextScene(Scene s);
    virtual Scene ProcessScene(Scene s) = 0;
    void Start();
    void Stop();
    bool Available();
protected:
    void Enqueue(Scene s);
    void Run();
    BlockingQueue<Scene> scheduleQueue;
    bool isOn = true;
    std::thread scheduleWorker;
};


#endif //SIGNAPSE_SCHEDULABLESCENELINKER_H
