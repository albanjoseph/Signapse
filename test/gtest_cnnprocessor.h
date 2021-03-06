#include <gtest/gtest.h>
#include "gtest_tools.h"


#include "CNNProcessor.h"
#include "SignapseUtils.h"

TEST(cnnprocessor_test, checkMakeBlob_dims){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene s = MakeScene("A");
    cv::Mat frame = s.frame;
    cv::Mat blob = cnn.MakeBlob(s);
    EXPECT_NE(frame.dims, blob.dims);
}

TEST(cnnprocessor_test, checkResult_a){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("A"));
    EXPECT_EQ(out.result, "A");
}

TEST(cnnprocessor_test, checkResult_b){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("B"));
    EXPECT_EQ(out.result, "B");
}
TEST(cnnprocessor_test, checkResult_c){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("C"));
    EXPECT_EQ(out.result, "C");
}
TEST(cnnprocessor_test, checkResult_d){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("D"));
    EXPECT_EQ(out.result, "D");
}

TEST(cnnprocessor_test, checkResult_e){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("E"));
    EXPECT_EQ(out.result, "E");
}

TEST(cnnprocessor_test, checkResult_f){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("F"));
    EXPECT_EQ(out.result, "F");
}

TEST(cnnprocessor_test, checkResult_g){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("G"));
    EXPECT_EQ(out.result, "G");
}
TEST(cnnprocessor_test, checkResult_h){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("H"));
    EXPECT_EQ(out.result, "H");
}
TEST(cnnprocessor_test, checkResult_j){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("J"));
    EXPECT_EQ(out.result, "J");
}

TEST(cnnprocessor_test, checkResult_l){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("L"));
    EXPECT_EQ(out.result, "L");
}

TEST(cnnprocessor_test, checkResult_m){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("M"));
    EXPECT_EQ(out.result, "M");
}

TEST(cnnprocessor_test, checkResult_n){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("N"));
    EXPECT_EQ(out.result, "N");
}

TEST(cnnprocessor_test, checkResult_o){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("O"));
    EXPECT_EQ(out.result, "O");
}

TEST(cnnprocessor_test, checkResult_p){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("P"));
    EXPECT_EQ(out.result, "P");
}

TEST(cnnprocessor_test, checkResult_q){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("Q"));
    EXPECT_EQ(out.result, "Q");
}

TEST(cnnprocessor_test, checkResult_r){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("R"));
    EXPECT_EQ(out.result, "R");
}

TEST(cnnprocessor_test, checkResult_s){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("S"));
    EXPECT_EQ(out.result, "S");
}

TEST(cnnprocessor_test, checkResult_t){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("T"));
    EXPECT_EQ(out.result, "T");
}

TEST(cnnprocessor_test, checkResult_u){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("U"));
    EXPECT_EQ(out.result, "U");
}

TEST(cnnprocessor_test, checkResult_w){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("W"));
    EXPECT_EQ(out.result, "W");
}

TEST(cnnprocessor_test, checkResult_x){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("X"));
    EXPECT_EQ(out.result, "X");
}

TEST(cnnprocessor_test, checkResult_y){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("Y"));
    EXPECT_EQ(out.result, "Y");
}

TEST(cnnprocessor_test, checkResult_z){
    CNNProcessorSettings settings;
    CNNProcessor cnn(settings);
    Scene out = cnn.ProcessScene(MakeScene("Z"));
    EXPECT_EQ(out.result, "Z");
}




