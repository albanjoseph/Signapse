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
#include "Gui.h"
#include "FrameEditor.h"
#include "SignapseUtils.h"

using namespace cv;
using namespace std;

//#define THRES 100





int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    SignapseUtils::welcomeMessage();
    Gui gui;
    CNNProcessor cnn(SignapseUtils::getModelPath());
    Camera c;
    gui.set_task('A');
    c.setBoundingBox(0.25, 0.25, 0.75, 0.75);
    c.registerFrameCallback(&gui);
    c.registerCNNCallback(&cnn);
    cnn.registerCallback(&gui);
    c.start_thread();
    gui.SetVisible(true);
    app.exec();
}

