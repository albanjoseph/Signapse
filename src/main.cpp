#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
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
#include "SceneLinkScheduler.h"
#include "SignapseUtils.h"
#include "DoubleSceneLinker.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    SignapseUtils::welcomeMessage();
    
    //make pipeline components
    SceneEditorSettings sceneEditorSettings;
    SceneEditor sceneEditor(&sceneEditorSettings);
    DoubleSceneLinker doubleLink;
    CNNProcessorSettings cnnSettings;
    CNNProcessor cnn(&cnnSettings, 10);
    
    Camera camera;
    Gui gui;
    
    camera.RegisterCallback(&sceneEditor);
    sceneEditor.RegisterCallback(&doubleLink);
    doubleLink.RegisterCallback(&cnn);
    doubleLink.RegisterSecondaryCallback(&gui);
    cnn.RegisterCallback(&gui);
    
    cnn.Start();
    camera.Start();

    gui.SetTask("A");
    gui.SetVisible(false);
    //app.exec();
    cin.get();
}

