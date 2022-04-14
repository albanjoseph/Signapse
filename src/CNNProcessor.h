#ifndef SIGNAPSE_CNNPROCESSOR_H
#define SIGNAPSE_CNNPROCESSOR_H

#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <stdio.h>
#include <chrono>
#include <thread>

#include "SchedulableLink.h"
#include "CNNProcessorSettings.h"
#include "SignapseUtils.h"


/*!
 * Schedulable Pipeline Link which performs network inference on each Scene, populating the results field.
 */
class CNNProcessor : public SchedulableLink{
public:
    Scene ProcessScene(Scene s);
    CNNProcessor(CNNProcessorSettings* s);
    cv::Mat MakeBlob(Scene scene);
    
protected:
    CNNProcessorSettings* settings;
    void LoadModel(std::string modelPath);
    cv::dnn::Net net;
};

#endif