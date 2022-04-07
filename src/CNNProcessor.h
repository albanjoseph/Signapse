#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <stdio.h>
#include <chrono>
#include <thread>

#include "SceneLinker.h"
#include "CNNProcessorSettings.h"
#include "SignapseUtils.h"


//!  CNNProcessor class.
/*!
    Class for interfacing with convolutional neural network
*/
class CNNProcessor : public SceneLinker{
public:
    void NextScene(Scene scene);
    
    CNNProcessor(CNNProcessorSettings* s);
    
    Scene ProcessScene(Scene scene);
    
    cv::Mat MakeBlob(Scene scene);
    
private:
    void threadLoop();
    
    void LoadModel(std::string modelPath);
    
    cv::dnn::Net net;
    CNNProcessorSettings* settings;
    std::thread cnnProcessorThread;
};

