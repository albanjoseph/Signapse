#include "camera.h"
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "SceneCallback.h"
#include "SceneLinker.h"
#include "CNNProcessorSettings.h"
#include <stdio.h>


//!  CNNProcessor class.
/*!
    Class for interfacing with convolutional neural network
*/
class CNNProcessor : public SceneProcessor{
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

