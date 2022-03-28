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
#include "SignapseUtils.h"

using namespace cv;
using namespace std;

//#define THRES 100





int main(int argc, char* argv[]){
    SignapseUtils::welcomeMessage();
    CNNProcessor cnn("models/asl-mobilenetv2.pb");
    Camera c;
    c.set_current_task('a');
    c.setBoundingBox(0.25, 0.25, 0.75, 0.75);
    c.registerCNNCallback(&cnn);
    c.start_thread();


    getchar();

}

