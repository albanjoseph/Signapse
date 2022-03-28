//
// Created by ross on 24/03/2022.
//
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "FrameEditor.h"



cv::Mat FrameEditor::drawBox(cv::Mat img, int *box) {
    int x  = box[0]; int y = box[1];
    int width = box[2] - box[0]; int height = box[3] - box[1];
    cv::Rect rect(x, y, width, height);
    cv::rectangle(img, rect, cv::Scalar(0, 255, 0));
    return img;
}
Scene FrameEditor::drawBox(Scene s) {
    cv::Mat temp = s.frame;
    int x  = s.regionOfInterest[0]; int y = s.regionOfInterest[1];
    int width = s.regionOfInterest[2] - s.regionOfInterest[0];
    int height = s.regionOfInterest[3] - s.regionOfInterest[1];
    cv::Rect rect(x, y, width, height);
    cv::rectangle(temp, rect, cv::Scalar(0,255,0));
    Scene ret = s;
    s.frame = temp;
    return s;
}
