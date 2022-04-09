#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <stdio.h>
#include <chrono>
#include <thread>

#include "NThreadSchedulableSceneLinker.h"
#include "CNNProcessorSettings.h"
#include "SignapseUtils.h"


//!  CNNProcessor class.
/*!
    Class for interfacing with convolutional neural network
*/
class CNNProcessor : public NThreadSchedulableSceneLinker{
public:
    Scene ProcessScene(Scene s);
    
    CNNProcessor(CNNProcessorSettings* s);
    
    CNNProcessor(CNNProcessorSettings* s, int nrThreads);
    
    cv::Mat MakeBlob(Scene scene);
    
private:
    void threadLoop();
    
    void LoadModel(std::string modelPath);
    
    cv::dnn::Net net;
    CNNProcessorSettings* settings;
    std::thread cnnProcessorThread;
};

