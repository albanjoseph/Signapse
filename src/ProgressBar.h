#ifndef SIGNAPSE_PROGRESSBAR_H
#define SIGNAPSE_PROGRESSBAR_H

#include "scene.h"

class ProgressBar{
public:
    ProgressBar();
    int get_progress(Scene s, char task);
    void reset_progress();
protected:
    int threshold;
    int count;
};

#endif