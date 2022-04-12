#ifndef SIGNAPSE_NTHREADEDCNNPROCESSOR_H
#define SIGNAPSE_NTHREADEDCNNPROCESSOR_H
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <stdio.h>
#include <chrono>
#include <thread>

#include "MultiThreadedSchedulableLink.h"
#include "CNNProcessor.h"


//!  CNNProcessor class.
/*!
    Class for interfacing with convolutional neural network
*/
class NThreadedCNNProcessor : public virtual MultiThreadedSchedulableLink, public CNNProcessor{
public:
    NThreadedCNNProcessor(CNNProcessorSettings* settings, int nrThreads);
    Scene ProcessScene(Scene s);

private:
    void LoadModel(std::string filename);
    BlockingQueue<cv::dnn::Net> netQueue;
};

#endif
