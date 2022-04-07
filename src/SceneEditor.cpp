//
// Created by ross on 24/03/2022.
//
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "SceneEditor.h"




void SceneEditor::NextScene(Scene scene){
   cv::Size sz = scene.frame.size();
   scene.regionOfInterest = BoundingBox((int)(sz.width * settings->relativeBoundingBox[0]),
                                        (int)(sz.height * settings->relativeBoundingBox[1]),
                                        (int)(sz.width * settings->relativeBoundingBox[2]),
                                        (int)(sz.height * settings->relativeBoundingBox[3]));
   Scene out = drawBox(scene);
   sceneCallback->NextScene(scene);
}

SceneEditor::SceneEditor(SceneEditorSettings* s) {
    settings = s;
}
//delete this
cv::Mat SceneEditor::drawBox(cv::Mat img, int *box) {
    int x  = box[0]; int y = box[1];
    int width = box[2] - box[0]; int height = box[3] - box[1];
    cv::Rect rect(x, y, width, height);
    cv::rectangle(img, rect, cv::Scalar(0, 255, 0));
    return img;
}

Scene SceneEditor::drawBox(Scene s) {
    cv::Mat temp = s.frame;
    int x  = s.regionOfInterest.UpperLeft.x; int y = s.regionOfInterest.UpperLeft.y;
    int width = s.regionOfInterest.LowerRight.x - x;
    int height = s.regionOfInterest.LowerRight.y - y;
    cv::Rect rect(x, y, width, height);
    cv::rectangle(temp, rect, cv::Scalar(0,255,0));
    Scene ret = s;
    s.frame = temp;
    return s;
}

void SceneEditor::SetBoundingBox(float upperLeftX, float upperLeftY, float lowerRightX, float lowerRightY) {
    settings->relativeBoundingBox[0] = upperLeftX;
    settings->relativeBoundingBox[1] = upperLeftY;
    settings->relativeBoundingBox[2] = lowerRightX;
    settings->relativeBoundingBox[3] = lowerRightY;
    for(int i = 0; i < 4; i++){
        float val = settings->relativeBoundingBox[i];
        if(val > 1.0f){
            settings->relativeBoundingBox[i] = 1.0f;
        }
        else if (val < 0.0f){
            settings->relativeBoundingBox[i] = 0.0f;
        }
    }
}