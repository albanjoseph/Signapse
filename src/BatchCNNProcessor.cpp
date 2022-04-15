#include "BatchCNNProcessor.h"

BatchCNNProcessor::BatchCNNProcessor(CNNProcessorSettings settings, int batchSz) : CNNProcessor(settings){
    batchSize = batchSz;
    time(&start);
    isOn = true;
    
}

void BatchCNNProcessor::Run(){
    while(isOn){
        std::vector<Scene> scenes(batchSize);
        for(int i = 0; i < batchSize; i++){
            Scene s = scheduleQueue.Pop();
            scenes[i] = s;
        }
        std::vector<Scene> processedScenes = ProcessScenes(scenes);
        if(!sceneCallback) continue;
        for(int i = 0; i < batchSize; i++){
            Scene s = processedScenes[i];
            sceneCallback->NextScene(s);
        }
    }
}

void BatchCNNProcessor::NextScene(Scene scene) {
    std::time_t current_time;
    time(&current_time);
    if(scheduleQueue.Size() < batchSize) {
        nrAllocated++;
        scheduleQueue.Push(scene);
    }
    float elapsed_seconds = current_time-start;
    float throughput = (double)nrAllocated / elapsed_seconds;
    printf("\r Throughput = %f", throughput);
    
}

void BatchCNNProcessor::Start(){
        scheduleWorker = std::thread(&BatchCNNProcessor::Run, this);
}

std::vector<Scene> BatchCNNProcessor::ProcessScenes(std::vector<Scene> scenes){
    std::vector<cv::Mat> mats(scenes.size());
    for(int i = 0; i<scenes.size(); i++){
        Scene scene = scenes[i];
        int x  = scene.regionOfInterest.UpperLeft.x; int y = scene.regionOfInterest.UpperLeft.y;
        int width = scene.regionOfInterest.LowerRight.x - x;
        int height = scene.regionOfInterest.LowerRight.y - y;
        cv::Mat roi = scene.frame(cv::Range(y, y+height), cv::Range(x, x+width));
        cv::Mat small;
        cv::resize(roi, small, cv::Size(settings.InputDim_x,settings.InputDim_y));
        mats[i] = small;
    }
    cv::Mat blob;
    cv::dnn::blobFromImages(mats, blob, (1.0 / 255.0));
    net.setInput(blob);
    cv::Mat out = net.forward();
    for (int i = 0; i < out.rows; ++i)
    {
        cv::Mat out_single = out.rowRange(i, i + 1);
        std::string result = PostProcess(out_single);
        scenes[i].result = result;
    }
    return scenes;
}

std::string BatchCNNProcessor::PostProcess(cv::Mat out)
{
    int _size = out.cols * out.rows;
    double min_val;
    double max_val;
    cv::Point min_pos;
    cv::Point max_pos;
    cv::minMaxLoc(out, &min_val, &max_val, &min_pos, &max_pos);
    
    int label = max_pos.x;
    return SignapseUtils::getLetterFromDigit(label);
}