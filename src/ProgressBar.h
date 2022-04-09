#ifndef SIGNAPSE_PROGRESSBAR_H
#define SIGNAPSE_PROGRESSBAR_H

#include <stdio.h>

#include "scene.h"

class ProgressBar{
public:
    ProgressBar();
    int get_progress(Scene s, std::string task);
    void reset_progress();
protected:
    int threshold;
    int count;
};

#endif