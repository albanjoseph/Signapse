#include "SceneCallback.h"

class SceneLinker : public SceneCallback{
public:
    void RegisterCallback(SceneCallback* scb);

protected:
    void NextScene(Scene scene);
    SceneCallback* sceneCallback = nullptr;
};

