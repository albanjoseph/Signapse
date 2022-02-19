//
// Blocking queue implementation, currently only blocks when Get is attempted while there are no elements inside the queue. In the future and max size could be defined and blocking could be added when the queue is full
//
#include "BlockingQueue.h"

template <typename T>
T BlockingQueue<T>::Pop() {
    std::unique_lock<std::mutex> lock(mutex);
    condition.wait(lock, [=]{ return !internalQueue.empty(); });
    T ret = internalQueue.back();
    internalQueue.pop_back();
    return ret;
}

template <typename T>
bool BlockingQueue<T>::IsEmpty(){
    return internalQueue.empty();
}

template <typename T>
void BlockingQueue<T>::Push(T toPush) {
    {
        std::unique_lock <std::mutex> lock(mutex);
        internalQueue.push_front(toPush);
    }
    condition.notify_all();
}
