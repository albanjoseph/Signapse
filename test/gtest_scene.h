#ifndef SIGNAPSE_GTEST_SCENE_H
#define SIGNAPSE_GTEST_SCENE_H
#include <gtest/gtest.h>

#include "Scene.h"

TEST(test_scene, checkinit_frame){
    Scene s;
    EXPECT_TRUE(s.frame.empty());
}

TEST(test_scene, checkinit_result){
    Scene s;
    EXPECT_EQ(s.result, "");
}

TEST(test_scene, checkinit_roi){
    Scene s;
    EXPECT_EQ(s.regionOfInterest.UpperLeft.x, 0);
    EXPECT_EQ(s.regionOfInterest.UpperLeft.y, 0);
    EXPECT_EQ(s.regionOfInterest.LowerRight.x, 0);
    EXPECT_EQ(s.regionOfInterest.LowerRight.y, 0);
}

#endif //SIGNAPSE_GTEST_SCENE_H
