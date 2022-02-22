#include "CNNProcessor.h"
#include <chrono>
#include <thread>
#include "scene.h"

CNNProcessor::CNNProcessor(Reel* setReadFrom){
 readFrom = setReadFrom;
}

void CNNProcessor::Loop(){
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        SelfPush();
    }
}

void CNNProcessor::SelfPush() {
    Scene frame = readFrom->Pop();
    sceneQueue.Push(frame);
}

