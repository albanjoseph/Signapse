#include <gtest/gtest.h>
#include "Camera.h"


TEST(camera_test, checkIsOn_init){
    Camera c;
    EXPECT_EQ(c.getOn(), true);
}

TEST(camera_test, checkIsOn_set){
    Camera c;
    c.setOn(false);
    EXPECT_EQ(c.getOn(), false);
    c.setOn(true);
    EXPECT_EQ(c.getOn(), true);
}

/*TEST(camera_test, checkBoundingBox_set_values){
    Camera c;
    c.setBoundingBox(0.0,0.0,0.0,0.0);
    float* bbox = c.getBoundingBox();
    for(int i = 0; i < 4; i++){
        EXPECT_EQ(bbox[i], 0.0f);
    }
}*/
/*
TEST(camera_test, checkBoundingBox_set_limits){
    Camera c;
    c.setBoundingBox(-1.0,-1.0,-1.0,-1.0);
    float* bbox = c.getBoundingBox();
    for(int i = 0; i < 4; i++){
        EXPECT_EQ(bbox[i], 0.0f);
    }
    c.setBoundingBox(2.0,2.0,2.0,2.0);
    bbox = c.getBoundingBox();
    for(int i = 0; i < 4; i++){
        EXPECT_EQ(bbox[i], 1.0f);
    }
}*/
