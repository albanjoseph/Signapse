//
// Created by ross on 09/02/2022.
//

#ifndef SIGNAPSE_CNNPROCESSOR_H
#define SIGNAPSE_CNNPROCESSOR_H

#include "reel.h"
//!  CNNProcessor class.
/*!
    Class for interfacing with convolutional neural network
*/
class CNNProcessor: public Reel{
public:
    //!  Public member function.
    /*!
        Loop.
    */
    void Loop();
    //!  Constructor takes Reel object as argument and assigns readFrom Reel to this value.
    /*!
        \param setReadFrom Reel to be copied to readFrom.
    */
    CNNProcessor(Reel setReadFrom);
    //!  Public member function.
    /*!
        Pops Scene from readFrom Reel and pushes to CNNProcessor own sceneQueue.
    */
    void SelfPush();

private:
    Reel readFrom;
};

#endif //SIGNAPSE_CNNPROCESSOR_H
