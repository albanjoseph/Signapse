//
// Created by ross on 09/02/2022.
//

#ifndef SIGNAPSE_CNNPROCESSOR_H
#define SIGNAPSE_CNNPROCESSOR_H


#include "reel.h"

class CNNProcessor: public Reel{
public:
    void Loop();
    CNNProcessor(Reel setReadFrom);
    void SelfPush();

private:
    Reel readFrom;
};

#endif //SIGNAPSE_CNNPROCESSOR_H
