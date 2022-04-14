#ifndef SIGNAPSE_PROGRESSBAR_H
#define SIGNAPSE_PROGRESSBAR_H

#include <stdio.h>

#include "Scene.h"
/*!
 * Simple class for keeping track of progress in learning a sign
 */
class ProgressBar{
public:
    ProgressBar();
    int GetProgress(std::string s, std::string task);
    void ResetProgress();
    void SetThreshold(int thres);
protected:
    int threshold;
    int count = 0;
};

#endif