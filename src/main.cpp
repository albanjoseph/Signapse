#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <stdio.h>
#include <queue>

#include "reel.h"
#include "Camera.h"
#include "CNNProcessor.h"
#include "stdlib.h"
#include "Gui.h"
#include "PreProcessor.h"
#include "SceneLinkScheduler.h"
#include "SignapseUtils.h"
#include "LinkSplitter.h"
#include "NThreadedCNNProcessor.h"
#include "BatchCNNProcessor.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    SignapseUtils::welcomeMessage();
    
    //make pipeline components
    PreProcessorSettings preProcessorSettings;
    PreProcessor preProcessor(&preProcessorSettings);
    LinkSplitter linkSplitter;
    CNNProcessorSettings cnnSettings;
    CNNProcessor cnn(&cnnSettings);
    
    Camera camera;
    Gui gui;
    
    camera.RegisterCallback(&preProcessor);
    preProcessor.RegisterCallback(&linkSplitter);
    linkSplitter.RegisterCallback(&cnn);
    linkSplitter.RegisterSecondaryCallback(&gui);
    cnn.RegisterCallback(&gui);
    
    cnn.Start();
    camera.Start();

    gui.SetTask("A");
    gui.SetVisible(true);
    app.exec();
    cin.get();
}

