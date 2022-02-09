//
// Created by ross on 09/02/2022.
//

#include <queue>

using namespace std;
#include "reel.h"



Reel::Reel(){
    frameQueue.push(10);
    frameQueue.push(20);
    frameQueue.push(30);
}
int Reel::Pop(){
    return frameQueue.pop();
}
int Reel::GetNumber(){
    return reelNr;
}
