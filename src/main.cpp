#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <stdio.h>
#include <queue>

#include "Camera.h"
#include "CNNProcessor.h"
#include "stdlib.h"
#include "Gui.h"
#include "PreProcessor.h"
#include "SignapseUtils.h"
#include "LinkSplitter.h"
#include "NThreadedCNNProcessor.h"
#include "BatchCNNProcessor.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]){
    SignapseUtils::welcomeMessage();
    
    //init Qt and Ui
    QApplication app(argc, argv);
    QMainWindow window;
    Ui_MainWindow ui;
    
    //make pipeline components
    CameraSettings cameraSettings;
    Camera camera(cameraSettings);
    PreProcessorSettings preProcessorSettings;
    PreProcessor preProcessor(&preProcessorSettings);
    LinkSplitter linkSplitter;
    CNNProcessorSettings cnnSettings;
    CNNProcessor cnn(&cnnSettings);
    Gui gui(&window, &ui);
    
    //register callbacks (link pipeline)
    camera.RegisterCallback(&preProcessor);
    preProcessor.RegisterCallback(&linkSplitter);
    linkSplitter.RegisterCallback(&cnn);
    linkSplitter.RegisterSecondaryCallback(&gui);
    cnn.RegisterCallback(&gui);
    
    //start camera and cnn
    cnn.Start();
    camera.Start();
    
    //start gui
    gui.SetVisible(true);
    app.exec(); //loops main thread
    
    //stop camera and cnn
    camera.Stop();
    cnn.Stop();
    
    //exit
    return 0;
}

