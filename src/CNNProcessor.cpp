#include "CNNProcessor.h"
#include <chrono>
#include <thread>
#include "scene.h"
#include "SignapseUtils.h"


void CNNProcessor::LoadModel(std::string modelPath){
    net = cv::dnn::readNetFromTensorflow(modelPath);
}

CNNProcessor::CNNProcessor(CNNProcessorSettings* s) {
    settings = s;
    LoadModel(settings->ModelPath);
}

cv::Mat CNNProcessor::MakeBlob(Scene scene){
    int x  = scene.regionOfInterest[0]; int y = scene.regionOfInterest[1];
    int width = scene.regionOfInterest[2] - scene.regionOfInterest[0];
    int height = scene.regionOfInterest[3] - scene.regionOfInterest[1];
    cv::Mat roi = scene.frame(cv::Range(y, y+height), cv::Range(x, x+width));
    cv::Mat rgb;
    cv::cvtColor(roi, rgb, cv::COLOR_BGR2RGB);
    cv::Mat smallRGB;
    cv::resize(rgb, smallRGB, cv::Size(settings->InputDim_x,settings->InputDim_y));
    cv::Mat blob;
    cv::dnn::blobFromImage(smallRGB, blob, (1.0 / 255.0));
    return blob;
}

Scene CNNProcessor::ProcessScene(Scene scene){
    cv::Mat blob = MakeBlob(scene);
    net.setInput(blob);
    cv::Mat prob = net.forward();
    cv::Point classIdPoint;
    double confidence;
    minMaxLoc(prob.reshape(1, 1), 0, &confidence, 0, &classIdPoint);
    int classId = classIdPoint.x;
    scene.result = SignapseUtils::getLetterFromDigit(classId);
    return scene;
}

void CNNProcessor::NextScene(Scene next) {
    Scene updatedFrame = ProcessScene(next);
    if(!sceneCallback) return;
    sceneCallback->NextScene(updatedFrame);
}



