#include "CNNProcessor.h"
#include <chrono>
#include <thread>
#include "scene.h"

void CNNProcessor::LoadModel(std::string modelPath){
    net = cv::dnn::readNetFromTensorflow(modelPath);
}

CNNProcessor::CNNProcessor(Reel* setReadFrom, std::string modelPath){
    readFrom = setReadFrom;
    LoadModel(modelPath);
}

void CNNProcessor::Loop(){
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        SelfPush();

    }
}

cv::Mat CNNProcessor::MakeBlob(Scene scene){
    //make blob
    cv::Mat roi = scene.frame(cv::Range(scene.regionOfInterest[0], scene.regionOfInterest[1]), cv::Range(scene.regionOfInterest[2], scene.regionOfInterest[3]));
    cv::Mat grey;
    cv::cvtColor(roi, grey, cv::COLOR_BGR2GRAY);
    cv::Mat smallGrey;
    cv::resize(grey, smallGrey, cv::Size(28,28));
    cv::Mat blob;
    cv::dnn::blobFromImage(smallGrey, blob);
    return blob;
}

Scene CNNProcessor::Inference(Scene scene){
    cv::Mat blob = MakeBlob(scene);
    net.setInput(blob);
    cv::Mat prob = net.forward();
    cv::Point classIdPoint;
    double confidence;
    minMaxLoc(prob.reshape(1, 1), 0, &confidence, 0, &classIdPoint);
    int classId = classIdPoint.x;
    printf("%d \n",classId);
    return scene;
}



void CNNProcessor::SelfPush() {
    Scene frame = readFrom->Pop();
    sceneQueue.Push(frame);

}

