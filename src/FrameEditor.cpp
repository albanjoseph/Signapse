//
// Created by ross on 24/03/2022.
//

#include "FrameEditor.h"

cv::Mat FrameEditor::drawBox(int img, int *box) {
    int x  = box[0]; int y = box[1];
    int width = box[2] - box[0]; int height = box[3] - box[1];
    cv::Rect rect(x, y, width, height);
    cv::rectangle(img, rect, cv::Scalar(0, 255, 0));
    return img;
}
