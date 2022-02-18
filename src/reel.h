//
// Created by ross on 09/02/2022.
//

#ifndef SIGNAPSE_REEL_H
#define SIGNAPSE_REEL_H
#include "scene.h"
#include <queue>
#include <mutex>
#include <condition_variable>

class Reel{
public:
    Reel();
    Scene Pop();
    int GetNumber();
    bool IsEmpty();

protected:
    int reelNr;
    std::queue<Scene> frameQueue;
};


#endif //SIGNAPSE_REEL_H
