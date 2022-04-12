#include "MultiThreadedSchedulableLink.h"
#include "BlockingQueue.cpp"


MultiThreadedSchedulableLink::MultiThreadedSchedulableLink(int nrThreads) {
    for (int i = 0; i < nrThreads; i++){
        threads.push_back(std::thread(&MultiThreadedSchedulableLink::Run, this));
    }
    time(&start);
}

MultiThreadedSchedulableLink::~MultiThreadedSchedulableLink() {
    for (int i = 0; i < threads.size(); i++){
        std::thread & t = threads[i];
        t.join();
    }
}

void MultiThreadedSchedulableLink::NextScene(Scene scene) {
    std::time_t current_time;
    time(&current_time);
    if(scheduleQueue.Size() < threads.size() * 2) {
        nrAllocated++;
        scheduleQueue.Push(scene);
    }
    float elapsed_seconds = current_time-start;
    float throughput = (double)nrAllocated / elapsed_seconds;
    printf("\r Throughput = %f", throughput);
    
}