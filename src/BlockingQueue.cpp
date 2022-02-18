//
// Created by ross on 18/02/2022.
//

#include "BlockingQueue.h"
template <typename T>
T BlockingQueue<T>::Get() {
    T t = internalQueue.front();
    internalQueue.pop();
    return t;
}
template <typename T>
void BlockingQueue<T>::Put(T toPush) {
    internalQueue.push(toPush);
}