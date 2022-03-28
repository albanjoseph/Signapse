#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <queue>
#include "reel.h"
#include "camera.h"
#include "CNNProcessor.h"
#include "stdlib.h"
#include "taskMaster.h"
#include "FrameEditor.h"

using namespace cv;
using namespace std;

//#define THRES 100


std::string getLetterFromDigit(int digit){
    std::string results[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V",
                             "W", "X", "Y", "Z", "del", "space", "nothing"};
    return results[digit];
}

void printProgress(float percentage, int prediction) {
    std::string letter = getLetterFromDigit(prediction);
    std::cout << "\r Prediction: " << letter << ", Progress: " << percentage << "% - keep signing!            ";
    fflush(stdout);
}

//returns a random nr range [0-25]
int makeTask(){
    return rand() % 25;
}


int main(int argc, char* argv[]){
    CNNProcessor cnn("models/asl-mobilenetv2.pb");
    Camera c;
    c.set_current_task('a');
    c.setBoundingBox(0.25, 0.25, 0.75, 0.75);
    c.registerCallback(&cnn);
    c.start_thread();

    getchar();

}

