#include "gtest/gtest.h"
#include "gtest_scene.h"
#include "gtest_camera.h"
#include "gtest_cnnprocessor.h"
#include "gtest_blockingqueue.h"
#include "gtest_preprocessor.h"
#include "gtest_signapseutils.h"
//#include ""


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}