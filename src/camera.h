//
// Created by adam on 09/02/2022.
//

#ifndef SIGNAPSE_CAMERA_H
#define SIGNAPSE_CAMERA_H
#include "reel.h"

class Camera: public Reel{
public:
    void Stream(); //Run in thread
    void Populate(); //Test feature
protected:
};


#endif //SIGNAPSE_CAMERA_H
