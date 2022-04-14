//
// Blocking queue implementation, currently only blocks when Get is attempted while there are no elements inside the queue. In the future and max size could be defined and blocking could be added when the queue is full
//
#include "BlockingQueue.h"
/*!
 * Pop method, uses mutex lock to sleep the current thread until data are available on the queue. This may be used to synchonise and schedule threads.
 * @tparam T
 * @return Element on deque back
 */
template <typename T>
T BlockingQueue<T>::Pop() {
    std::unique_lock<std::mutex> lock(mutex);
    condition.wait(lock, [=]{ return !internalQueue.empty(); });
    T ret = internalQueue.back();
    internalQueue.pop_back();
    return ret;
}
/*!
 *
 * @tparam T
 * @return true if internal queue empty, false otherwise
 */
template <typename T>
bool BlockingQueue<T>::IsEmpty(){
    return internalQueue.empty();
}

/*!
 * Gets the current length of elements in the queue.
 * @tparam T
 * @return size of internal deque
 */
template <typename T>
int BlockingQueue<T>::Size(){
    return internalQueue.size();
}

/*!
  * adds element to the queue.
  * @tparam T
  * @param toPush
  */
template <typename T>
void BlockingQueue<T>::Push(T toPush) {
    {
        internalQueue.push_front(toPush);
    }
    condition.notify_all();
}
