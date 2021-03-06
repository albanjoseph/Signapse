//
// Created by ross on 18/02/2022.
//

#ifndef SIGNAPSE_BLOCKINGQUEUE_H
#define SIGNAPSE_BLOCKINGQUEUE_H
#include <deque>
#include <mutex>
#include <condition_variable>
#include "Scene.h"


template <typename T>
//!  BlockingQueue Class
/*!
    
*/

/*!
 * Class to wrap around std::deque and block thread execution when no data is available at the output.
 * @tparam T Type of elements in the queue
 */
class BlockingQueue {
public:
    void Push(T toPush);
    T Pop();
    bool IsEmpty();
    int Size();
private:
    std::deque<T> internalQueue;
    std::mutex mutex;
    std::condition_variable condition;
};


#endif //SIGNAPSE_BLOCKINGQUEUE_H
