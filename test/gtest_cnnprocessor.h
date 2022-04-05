#include <gtest/gtest.h>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>
#include "CNNProcessor.h"
#include "SignapseUtils.h"

Scene MakeScene(std::string letter){
    std::string filepath = "asl_alphabet_test/" + letter + "_test.jpg";
    cv::Mat test_frame = cv::imread(filepath);
    cv::Mat flipped; cv::flip(test_frame, flipped, 1);
    Scene test_scene;
    test_scene.regionOfInterest[0] = 0;
    test_scene.regionOfInterest[1] = 0;
    test_scene.regionOfInterest[2] = flipped.rows;
    test_scene.regionOfInterest[3] = flipped.cols;
    test_scene.frame = flipped;
    return test_scene;
}

TEST(cnnprocessor_test, checkResult_a){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("A"));
    EXPECT_EQ(out.result, "A");
}

TEST(cnnprocessor_test, checkResult_b){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("B"));
    EXPECT_EQ(out.result, "B");
}
TEST(cnnprocessor_test, checkResult_c){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("C"));
    EXPECT_EQ(out.result, "C");
}
TEST(cnnprocessor_test, checkResult_d){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("D"));
    EXPECT_EQ(out.result, "D");
}

TEST(cnnprocessor_test, checkResult_e){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("E"));
    EXPECT_EQ(out.result, "E");
}

TEST(cnnprocessor_test, checkResult_f){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("F"));
    EXPECT_EQ(out.result, "F");
}

TEST(cnnprocessor_test, checkResult_g){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("G"));
    EXPECT_EQ(out.result, "G");
}
TEST(cnnprocessor_test, checkResult_h){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("H"));
    EXPECT_EQ(out.result, "H");
}
TEST(cnnprocessor_test, checkResult_j){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("J"));
    EXPECT_EQ(out.result, "J");
}
TEST(cnnprocessor_test, checkResult_k){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("K"));
    EXPECT_EQ(out.result, "K");
}

TEST(cnnprocessor_test, checkResult_l){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("L"));
    EXPECT_EQ(out.result, "L");
}

TEST(cnnprocessor_test, checkResult_m){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("M"));
    EXPECT_EQ(out.result, "M");
}

TEST(cnnprocessor_test, checkResult_n){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("N"));
    EXPECT_EQ(out.result, "N");
}

TEST(cnnprocessor_test, checkResult_o){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("O"));
    EXPECT_EQ(out.result, "O");
}

TEST(cnnprocessor_test, checkResult_p){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("P"));
    EXPECT_EQ(out.result, "P");
}

TEST(cnnprocessor_test, checkResult_q){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("Q"));
    EXPECT_EQ(out.result, "Q");
}

TEST(cnnprocessor_test, checkResult_r){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("R"));
    EXPECT_EQ(out.result, "R");
}

TEST(cnnprocessor_test, checkResult_s){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("S"));
    EXPECT_EQ(out.result, "S");
}

TEST(cnnprocessor_test, checkResult_t){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("T"));
    EXPECT_EQ(out.result, "T");
}

TEST(cnnprocessor_test, checkResult_u){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("U"));
    EXPECT_EQ(out.result, "U");
}

TEST(cnnprocessor_test, checkResult_w){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("W"));
    EXPECT_EQ(out.result, "W");
}

TEST(cnnprocessor_test, checkResult_x){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("X"));
    EXPECT_EQ(out.result, "X");
}

TEST(cnnprocessor_test, checkResult_y){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("Y"));
    EXPECT_EQ(out.result, "Y");
}

TEST(cnnprocessor_test, checkResult_z){
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("Z"));
    EXPECT_EQ(out.result, "Z");
}

