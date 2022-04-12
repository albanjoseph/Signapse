#ifndef SIGNAPSE_GTEST_PREPROCESSOR_H
#define SIGNAPSE_GTEST_PREPROCESSOR_H
#include "gtest_tools.h"

#include "PreProcessor.h"


TEST(preprocessor_test, checkBBox_set){
    EndpointTester endpoint;
    PreProcessorSettings settings;
    PreProcessor pp(&settings);
    pp.SetBoundingBox(0.0f, 0.0f, 1.0f, 1.0f);
    Scene s = MakeScene("A");
    pp.RegisterCallback(&endpoint);
    pp.NextScene(s);
    EXPECT_EQ(endpoint.currentScene.regionOfInterest.UpperLeft.x, 0);
    EXPECT_EQ(endpoint.currentScene.regionOfInterest.UpperLeft.y, 0);
    EXPECT_EQ(endpoint.currentScene.regionOfInterest.LowerRight.x, endpoint.currentScene.frame.rows);
    EXPECT_EQ(endpoint.currentScene.regionOfInterest.LowerRight.y, endpoint.currentScene.frame.cols);
}








#endif //SIGNAPSE_GTEST_PREPROCESSOR_H
