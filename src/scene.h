//
// Created by adam on 09/02/2022.
//
#include <opencv2/core.hpp>
#ifndef SIGNAPSE_SCENE_H
#define SIGNAPSE_SCENE_H

struct Result{
    char sign;
    int conf;
};

struct Scene{
    cv::Mat frame;
    int timestamp;
    char task;
    Result result[10];
};

#endif //SIGNAPSE_SCENE_H