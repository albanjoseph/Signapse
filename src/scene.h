//
// Created by adam on 09/02/2022.
//

#ifndef SIGNAPSE_SCENE_H
#define SIGNAPSE_SCENE_H

struct Result{
    char sign;
    int conf;
};

struct Scene{
    char data[32]; //Currently arbitrary size
    int timestamp;
    char task;
    Result result[10];
};

#endif //SIGNAPSE_SCENE_H