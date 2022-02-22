//
// Created by ross on 09/02/2022.
//

#ifndef SIGNAPSE_REEL_H
#define SIGNAPSE_REEL_H
#include "scene.h"
#include "BlockingQueue.h"
#include "BlockingQueue.cpp"


class Reel{
public:
    Reel();
    Scene Pop();
    int GetNumber();
    bool IsEmpty();


protected:
    int reelNr;
    BlockingQueue<Scene> sceneQueue;
};


#endif //SIGNAPSE_REEL_H
