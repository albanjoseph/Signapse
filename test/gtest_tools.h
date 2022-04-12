#ifndef SIGNAPSE_GTEST_TOOLS_H
#define SIGNAPSE_GTEST_TOOLS_H

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>

#include "PipelineLink.h"

class EndpointTester : public PipelineLink{
public:
    void NextScene(Scene s){
        currentScene = s;
    }
    Scene currentScene;
};

Scene MakeScene(std::string letter){
    std::string filepath = "test/asl_alphabet_test/" + letter + "_test.jpg";
    cv::Mat test_frame = cv::imread(filepath);
    cv::Mat flipped; cv::flip(test_frame, flipped, 1);
    Scene test_scene;
    test_scene.regionOfInterest.UpperLeft.x = 0;
    test_scene.regionOfInterest.UpperLeft.y = 0;
    test_scene.regionOfInterest.LowerRight.x = flipped.rows;
    test_scene.regionOfInterest.LowerRight.y = flipped.cols;
    test_scene.frame = flipped;
    return test_scene;
}



#endif //SIGNAPSE_GTEST_TOOLS_H
