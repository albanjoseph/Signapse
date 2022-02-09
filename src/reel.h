//
// Created by ross on 09/02/2022.
//

#ifndef SIGNAPSE_REEL_H
#define SIGNAPSE_REEL_H
#include <queue>

class Reel{
public:
    Reel();
    int Pop();
    int GetNumber();

private:
    int reelNr;
    std::queue<int> frameQueue;
};


#endif //SIGNAPSE_REEL_H
