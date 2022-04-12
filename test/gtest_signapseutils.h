#include <gtest/gtest.h>
#include "SignapseUtils.h"

TEST(signapseutils_test, checkModelPath_ret){
    std::string modelPath = SignapseUtils::getModelPath();
    EXPECT_EQ(modelPath, MODEL_PATH);
}

TEST(signapseutils_test, checkMakeTask_int){
    int task = SignapseUtils::makeTask();
    EXPECT_LE(task, NR_TASKS);
}

