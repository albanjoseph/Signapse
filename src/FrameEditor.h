//
// Created by ross on 24/03/2022.
//

#ifndef SIGNAPSE_FRAMEEDITOR_H
#define SIGNAPSE_FRAMEEDITOR_H
#include <opencv2/core.hpp>
#include "scene.h"


class FrameEditor {
public:
    static cv::Mat drawBox(cv::Mat img, int box[4]);
    static Scene drawBox(Scene s);
};

#endif //SIGNAPSE_FRAMEEDITOR_H
