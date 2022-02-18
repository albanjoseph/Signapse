//
// Created by ross on 18/02/2022.
//
#include "BlockingQueue.h"

template <typename T>
T BlockingQueue<T>::Get() {
    std::unique_lock<std::mutex> lock(mutex);
    condition.wait(lock, [=]{ return !internalQueue.empty(); });
    T ret = internalQueue.back();
    internalQueue.pop_back();
    return ret;
}

template <typename T>
void BlockingQueue<T>::Put(T toPush) {
    {
        std::unique_lock <std::mutex> lock(mutex);
        internalQueue.push_front(toPush);
    }
    condition.notify_all();
}
