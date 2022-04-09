#ifndef SIGNAPSE_NTHREADSCHEDULABLESCENELINKER_H
#define SIGNAPSE_NTHREADSCHEDULABLESCENELINKER_H

#include <stdlib.h>
#include <thread>

#include "SchedulableSceneLinker.h"

class NThreadSchedulableSceneLinker : public SchedulableSceneLinker {
public:
    NThreadSchedulableSceneLinker(int nrThreads);
    void NextScene(Scene scene);
    ~NThreadSchedulableSceneLinker();

private:
    std::vector<std::thread> threads;
};


#endif //SIGNAPSE_NTHREADSCHEDULABLESCENELINKER_H
