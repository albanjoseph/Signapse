#include <opencv2/core.hpp>
#include "scene.h"
#include "SceneLinker.h"
#include "SceneEditorSettings.h"

class SceneEditor : public SceneLinker{
public:
    SceneEditor(SceneEditorSettings* settings);
    void NextScene(Scene scene);
    void SetBoundingBox(float upperLeftX, float upperLeftY, float lowerRightX, float lowerRightY);
    
private:
    Scene drawBox(Scene s);
    Scene switchRGB2BGR(Scene s);
    SceneEditorSettings* settings;
};

