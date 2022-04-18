#include "PipelineLink.h"

/*!
 * Used to register the next pipeline element.
 * @param scb reference to the next pipeline element
 */
void PipelineLink::RegisterCallback(SceneCallback *scb) {
    sceneCallback = scb;
}
/*!
 * Default NextScene implementation, simply passes the scene on to the registered callback
 * @param scene
 */
void PipelineLink::NextScene(Scene scene) {
    if(!sceneCallback) return;
    sceneCallback->NextScene(scene);
}