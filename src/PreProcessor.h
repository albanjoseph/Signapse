#include <opencv2/core.hpp>
#include "Scene.h"
#include "PipelineLink.h"
#include "PreProcessorSettings.h"

class PreProcessor : public PipelineLink{
public:
    PreProcessor(PreProcessorSettings* settings);
    void NextScene(Scene scene);
    void SetBoundingBox(float upperLeftX, float upperLeftY, float lowerRightX, float lowerRightY);
    
private:
    Scene drawBox(Scene s);
    Scene switchRGB2BGR(Scene s);
    PreProcessorSettings* settings;
};

