//
// Created by ross on 09/04/2022.
//

#include "NThreadSchedulableSceneLinker.h"
#include "BlockingQueue.cpp"


NThreadSchedulableSceneLinker::NThreadSchedulableSceneLinker(int nrThreads) {
    for (int i = 0; i < nrThreads; i++){
        threads.push_back(std::thread(&NThreadSchedulableSceneLinker::Run, this));
    }
}

NThreadSchedulableSceneLinker::~NThreadSchedulableSceneLinker() {
    for (int i = 0; i < threads.size(); i++){
        std::thread & t = threads[i];
        t.join();
    }
}

void NThreadSchedulableSceneLinker::NextScene(Scene scene) {
    if(scheduleQueue.Size() < threads.size()) {
        scheduleQueue.Push(scene);
    }
}