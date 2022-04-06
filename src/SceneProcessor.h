#include "SceneCallback.h"

class SceneProcessor : public SceneCallback{
public:
    void RegisterCallback(SceneCallback* scb);

protected:
    void NextScene(Scene scene);
    SceneCallback* sceneCallback = nullptr;
};

