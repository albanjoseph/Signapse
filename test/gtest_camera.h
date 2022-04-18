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

