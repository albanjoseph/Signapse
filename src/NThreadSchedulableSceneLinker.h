#ifndef SIGNAPSE_NTHREADSCHEDULABLESCENELINKER_H
#define SIGNAPSE_NTHREADSCHEDULABLESCENELINKER_H

#include <stdlib.h>
#include <thread>
#include <chrono>
#include <ctime>

#include "SchedulableLink.h"

class NThreadSchedulableSceneLinker : virtual public SchedulableLink {
public:
    NThreadSchedulableSceneLinker(int nrThreads);
    void NextScene(Scene scene);
    ~NThreadSchedulableSceneLinker();

protected:
    std::time_t start;
    int nrAllocated = 0;
    std::vector<std::thread> threads;
};


#endif //SIGNAPSE_NTHREADSCHEDULABLESCENELINKER_H
