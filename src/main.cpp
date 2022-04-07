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
#include "SceneEditor.h"
#include "SignapseUtils.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    SignapseUtils::welcomeMessage();
    
    //make pipeline components
    SceneEditorSettings sceneEditorSettings;
    SceneEditor sceneEditor(&sceneEditorSettings);
    CNNProcessorSettings cnnSettings;
    CNNProcessor cnn(&cnnSettings);
    Camera c;
    Gui gui;
    
    //register callbacks
    c.RegisterCallback(&sceneEditor);
    sceneEditor.RegisterCallback(&cnn);
    cnn.RegisterCallback(&gui);
    
    //start application
    gui.set_task('A');
    c.start_thread();
    gui.SetVisible(true);
    app.exec();
}

