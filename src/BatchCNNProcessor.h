#ifndef SIGNAPSE_BATCHCNNPROCESSOR_H
#define SIGNAPSE_BATCHCNNPROCESSOR_H

#include "CNNProcessor.h"

#include <chrono>
#include <ctime>

class BatchCNNProcessor : public CNNProcessor {
public:
    BatchCNNProcessor(CNNProcessorSettings settings, int batchSize);
    std::vector<Scene> ProcessScenes(std::vector<Scene> scenes);
    std::string PostProcess(cv::Mat out);
    void NextScene(Scene s);
    void Run();
    void Start();
    
private:
    int batchSize = 0;
    std::time_t start;
    int nrAllocated = 0;
};


#endif //SIGNAPSE_BATCHCNNPROCESSOR_H
