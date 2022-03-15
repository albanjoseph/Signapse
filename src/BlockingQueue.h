//
// Created by ross on 18/02/2022.
//

#ifndef SIGNAPSE_BLOCKINGQUEUE_H
#define SIGNAPSE_BLOCKINGQUEUE_H
#include <deque>
#include <mutex>
#include <condition_variable>
#include "scene.h"


template <typename T>
//!  BlockingQueue Class
/*!
    
*/
class BlockingQueue {
public:
    void Push(T toPush);
    T Pop();
    bool IsEmpty();

private:
    std::deque<T> internalQueue;
    std::mutex mutex;
    std::condition_variable condition;
};


#endif //SIGNAPSE_BLOCKINGQUEUE_H
