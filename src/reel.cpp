//
// Created by ross on 09/02/2022.
//

#include <queue>

using namespace std;
#include "reel.h"
#include "scene.h"


Reel::Reel(){

}
Scene Reel::Pop(){
    Scene elem = frameQueue.front();
    frameQueue.pop();
    return elem;
}
int Reel::GetNumber(){
    return reelNr;
}
