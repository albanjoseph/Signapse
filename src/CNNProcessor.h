#ifndef SIGNAPSE_CNNPROCESSOR_H
#define SIGNAPSE_CNNPROCESSOR_H

#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <stdio.h>
#include <chrono>
#include <thread>

#include "SchedulableSceneLinker.h"
#include "CNNProcessorSettings.h"
#include "SignapseUtils.h"


//!  CNNProcessor class.
/*!
    Class for interfacing with convolutional neural network
*/
class CNNProcessor : virtual public SchedulableSceneLinker{
public:
    Scene ProcessScene(Scene s);
    
    CNNProcessor(CNNProcessorSettings* s);
    
    cv::Mat MakeBlob(Scene scene);

protected:
    CNNProcessorSettings* settings;
    void threadLoop();
    
    void LoadModel(std::string modelPath);
    cv::dnn::Net net;

private:
    std::thread cnnProcessorThread;
};

#endif