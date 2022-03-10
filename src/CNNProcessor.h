//
// Created by ross on 09/02/2022.
//

#ifndef SIGNAPSE_CNNPROCESSOR_H
#define SIGNAPSE_CNNPROCESSOR_H

#include "reel.h"
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <stdio.h>

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
    CNNProcessor(Reel* setReadFrom, std::string modelPath);
    //!  Public member function.
    /*!
        Pops Scene from readFrom Reel and pushes to CNNProcessor own sceneQueue.
    */
    void SelfPush();
    Scene Inference(Scene scene);
    cv::Mat MakeBlob(Scene scene);



private:
    void LoadModel(std::string modelPath);
    Reel* readFrom;
    cv::dnn::Net net;
};

#endif //SIGNAPSE_CNNPROCESSOR_H
