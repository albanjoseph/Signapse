//
// Created by ross on 09/02/2022.
//

#ifndef SIGNAPSE_CNNPROCESSOR_H
#define SIGNAPSE_CNNPROCESSOR_H

#include "reel.h"
#include "camera.h"
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <stdio.h>

//!  CNNProcessor class.
/*!
    Class for interfacing with convolutional neural network
*/
class CNNProcessor: public Reel, public CameraCallback{
public:
    virtual  void  nextScene(Scene next);
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
    CNNProcessor(std::string modelPath);
    //!  Public member function.
    /*!
        Pops Scene from readFrom Reel and pushes to CNNProcessor own sceneQueue.
    */
    void SelfPush();
    int Inference(Scene scene);
    cv::Mat MakeBlob(Scene scene);
    void start_thread();



private:
    void threadLoop();
    void LoadModel(std::string modelPath);
    Reel* readFrom;
    cv::dnn::Net net;
    std::thread cnnProcessorThread;

};

#endif //SIGNAPSE_CNNPROCESSOR_H
