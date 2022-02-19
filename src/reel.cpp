//
// Created by ross on 09/02/2022.
//

#include "reel.h"
#include "scene.h"
using namespace std;


Reel::Reel(){

}

bool Reel::IsEmpty(){
    return frameQueue.IsEmpty();
}

Scene Reel::Pop(){
    return frameQueue.Pop();
}

int Reel::GetNumber(){
    return reelNr;
}
