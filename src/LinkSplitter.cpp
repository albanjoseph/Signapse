#include "LinkSplitter.h"

/*!
 * Override of NextScene to pass scene reference to a maximum of two registered callbacks
 * @param s scene
 */
void LinkSplitter::NextScene(Scene s) {
    if(sceneCallback) sceneCallback->NextScene(s);
    if(secondarySceneCallback) secondarySceneCallback->NextScene(s);
}
/*!
 * Used to register a secondary callback.
 * @param scb callback to register.
 */
void LinkSplitter::RegisterSecondaryCallback(SceneCallback *scb) {
    secondarySceneCallback = scb;
}