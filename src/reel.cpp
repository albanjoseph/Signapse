//
// Created by ross on 09/02/2022.
//

#include <queue>

using namespace std;
#include "reel.h"
#include "scene.h"

Reel::Reel(){

}
bool Reel::IsEmpty(){
    return frameQueue.empty();
}
unique_lock<std::mutex> lck(readerMutex);
while(queue<T>::empty()) {
isEmpty.wait(lck);
}
T value = queue<T>::front();
queue<T>::pop();
Scene Reel::Pop(){
    unique_lock<std::mutex> lock(readerMutex);
    while(IsEmpty()){
        isEmpty.wait(lock);
    }
    Scene elem = frameQueue.front();
    frameQueue.pop();
    return elem;
}
int Reel::GetNumber(){
    return reelNr;
}
