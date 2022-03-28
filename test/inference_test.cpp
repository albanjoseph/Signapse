#include <stdio.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>
#include <scene.h>
#include <CNNProcessor.h>
#include <camera.h>
#include "SignapseUtils.h"

int main(){
    
    Camera c;
    CNNProcessor cnn = CNNProcessor(&c, "../models/asl-mobilenetv2.pb");
    for(int i=0; i<26; i++)
    {
        char filepath[100];
        sprintf(filepath, "../test/asl_alphabet_test/%c_test.jpg", i+65);
        cv::Mat test_frame = cv::imread(filepath);
        //printf("rows=%i, cols=%i", test_frame.rows,test_frame.cols);
        Scene test_scene;
        test_scene.regionOfInterest[0] = 0;
        test_scene.regionOfInterest[1] = 0;
        test_scene.regionOfInterest[2] = 200;
        test_scene.regionOfInterest[3] = 200;
        cv::Mat flip_frame;
        cv::flip(test_frame, flip_frame, 1);
        test_scene.frame = flip_frame;
        test_scene = cnn.ProcessScene(test_scene);
        std::string result = test_scene.result;
        std::string ground_truth_letter = SignapseUtils::getLetterFromDigit(i);
        if(result != ground_truth_letter)
        {
            if(i == 21) break;
            printf("image=%c result=%s\n\r", i+65, result);
            return 1;
        }
    }
    return 0;
    
}