#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include "PreProcessor.h"

void PreProcessor::NextScene(Scene scene){
   cv::Size sz = scene.frame.size();
   scene.regionOfInterest = BoundingBox((int)(sz.width * settings->relativeBoundingBox[0]),
                                        (int)(sz.height * settings->relativeBoundingBox[1]),
                                        (int)(sz.width * settings->relativeBoundingBox[2]),
                                        (int)(sz.height * settings->relativeBoundingBox[3]));
   Scene out = switchRGB2BGR(scene);
   out = drawBox(scene);
    if(!sceneCallback) return;
   sceneCallback->NextScene(out);
}

PreProcessor::SceneEditor(SceneEditorSettings* s) {
    settings = s;
}

Scene PreProcessor::switchRGB2BGR(Scene s) {
    cv::Mat temp = s.frame;
    cv::cvtColor(temp, s.frame, cv::COLOR_BGR2RGB);
    return s;
}

Scene PreProcessor::drawBox(Scene s) {
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

void PreProcessor::SetBoundingBox(float upperLeftX, float upperLeftY, float lowerRightX, float lowerRightY) {
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
