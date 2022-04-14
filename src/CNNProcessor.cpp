#include "CNNProcessor.h"

/*!
 * Loads neural network from location on disk
 * @param modelPath
 */
void CNNProcessor::LoadModel(std::string modelPath){
    net = cv::dnn::readNetFromTensorflow(modelPath);
}

CNNProcessor::CNNProcessor(CNNProcessorSettings* s) {
    settings = s;
    LoadModel(settings->ModelPath);
}

/*!
 * Makes OpenCV image "blob" from the region of interest in the frame. Blob format is required for inference.
 * @param scene
 * @return matrix image blob, ready for inference
 */
cv::Mat CNNProcessor::MakeBlob(Scene scene){
    int x  = scene.regionOfInterest.UpperLeft.x; int y = scene.regionOfInterest.UpperLeft.y;
    int width = scene.regionOfInterest.LowerRight.x - x;
    int height = scene.regionOfInterest.LowerRight.y - y;
    cv::Mat roi = scene.frame(cv::Range(y, y+height), cv::Range(x, x+width));
    cv::Mat small;
    cv::resize(roi, small, cv::Size(settings->InputDim_x,settings->InputDim_y));
    cv::Mat blob;
    cv::dnn::blobFromImage(small, blob, (1.0 / 255.0));
    return blob;
}

/*!
 * Executed network inference on given scene, populates the scene with results.
 * @param scene input scene
 * @return output processed scene
 */
Scene CNNProcessor::ProcessScene(Scene scene){
    if(scene.frame.empty()) return scene;
    cv::Mat blob = MakeBlob(scene);
    net.setInput(blob);
    cv::Mat prob = net.forward();
    cv::Point classIdPoint;
    double confidence;
    minMaxLoc(prob.reshape(1, 1), 0, &confidence, 0, &classIdPoint);
    int classId = classIdPoint.x;
    scene.result = SignapseUtils::getLetterFromDigit(classId);
    return scene;
}


