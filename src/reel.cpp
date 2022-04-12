//
// Created by ross on 09/02/2022.
//

#include "reel.h"
#include "Scene.h"
using namespace std;


Reel::Reel(){

}

bool Reel::IsEmpty(){
    return sceneQueue.IsEmpty();
}

Scene Reel::Pop(){
    return sceneQueue.Pop();
}

int Reel::GetNumber(){
    return reelNr;
}
