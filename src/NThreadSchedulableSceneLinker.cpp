//
// Created by ross on 09/04/2022.
//

#include "NThreadSchedulableSceneLinker.h"
#include "BlockingQueue.cpp"


NThreadSchedulableSceneLinker::NThreadSchedulableSceneLinker(int nrThreads) {
    for (int i = 0; i < nrThreads; i++){
        threads.push_back(std::thread(&NThreadSchedulableSceneLinker::Run, this));
    }
    time(&start);
}

NThreadSchedulableSceneLinker::~NThreadSchedulableSceneLinker() {
    for (int i = 0; i < threads.size(); i++){
        std::thread & t = threads[i];
        t.join();
    }
}

void NThreadSchedulableSceneLinker::NextScene(Scene scene) {
    std::time_t current_time;
    time(&current_time);
    if(scheduleQueue.Size() < threads.size()) {
        nrAllocated++;
        scheduleQueue.Push(scene);
    }
    float elapsed_seconds = current_time-start;
    float throughput = (double)nrAllocated / elapsed_seconds;
    printf("\r Throughput = %f", throughput);
    
}