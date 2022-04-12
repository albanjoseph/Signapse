#ifndef SIGNAPSE_GTEST_BLOCKINGQUEUE_H
#define SIGNAPSE_GTEST_BLOCKINGQUEUE_H

#include "BlockingQueue.h"
#include "BlockingQueue.cpp"

TEST(blockingqueue_test, checkInit_empty){
    BlockingQueue<int> queue;
    EXPECT_EQ(queue.Size(), 0);
}

TEST(blockingqueue_test, checkPush_size){
    BlockingQueue<int> queue;
    for(int i = 1; i<11; i++){
        queue.Push(i);
        EXPECT_EQ(queue.Size(), i);
    }
}

TEST(blockingqueue_test, checkIntegrity_int){
    BlockingQueue<int> queue;
    int toQueue = 314159;
    queue.Push(toQueue);
    int popped = queue.Pop();
    EXPECT_EQ(toQueue, popped);
}

#endif //SIGNAPSE_GTEST_BLOCKINGQUEUE_H
