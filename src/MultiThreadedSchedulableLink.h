#ifndef SIGNAPSE_NTHREADSCHEDULABLESCENELINKER_H
#define SIGNAPSE_NTHREADSCHEDULABLESCENELINKER_H

#include <stdlib.h>
#include <thread>
#include <chrono>
#include <ctime>

#include "SchedulableLink.h"

class MultiThreadedSchedulableLink : virtual public SchedulableLink {
public:
    MultiThreadedSchedulableLink(int nrThreads);
    void NextScene(Scene scene);
    ~MultiThreadedSchedulableLink();

protected:
    std::time_t start;
    int nrAllocated = 0;
    std::vector<std::thread> threads;
};


#endif //SIGNAPSE_NTHREADSCHEDULABLESCENELINKER_H
