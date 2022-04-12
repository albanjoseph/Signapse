#include "NThreadedCNNProcessor.h"
#include "BlockingQueue.cpp"

NThreadedCNNProcessor::NThreadedCNNProcessor(CNNProcessorSettings* settings, int nrThreads) : CNNProcessor(settings),
                                                                                              MultiThreadedSchedulableLink(nrThreads) {
    LoadModel(settings->ModelPath);
}

void NThreadedCNNProcessor::LoadModel(std::string filename) {
    for(int i =0; i<threads.size(); i++){
        netQueue.Push(cv::dnn::readNetFromTensorflow(filename));
        netQueue.Push(cv::dnn::readNetFromTensorflow(filename));
    }
    printf("\nsize at init: %d \n", netQueue.Size() );
}

Scene NThreadedCNNProcessor::ProcessScene(Scene scene) {
    printf("%d \n", netQueue.Size());
    cv::Mat blob = MakeBlob(scene);
    //get an available network
    cv::dnn::Net current_net = netQueue.Pop();
    current_net.setInput(blob);
    cv::Mat prob = current_net.forward();
    for(int i = 0; i < 10; i++){
        current_net.forward();
    }
    cv::Point classIdPoint;
    double confidence;
    minMaxLoc(prob.reshape(1, 1), 0, &confidence, 0, &classIdPoint);
    int classId = classIdPoint.x;
    scene.result = SignapseUtils::getLetterFromDigit(classId);
    //return the network to the pool
    netQueue.Push(current_net);
    return scene;
}

