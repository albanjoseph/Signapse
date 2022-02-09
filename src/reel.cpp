//
// Created by ross on 09/02/2022.
//

#include <queue>

using namespace std;
#include "reel.h"

class Reel{
public:
    Reel(){
        frameQueue.push(10);
        frameQueue.push(20);
        frameQueue.push(30);
    }
    int Pop(){
        return frameQueue.pop();
    }
    int GetNumber(){
        return reelNr;
    }

private:
    int reelNr = 10;
    queue<int> frameQueue;


};