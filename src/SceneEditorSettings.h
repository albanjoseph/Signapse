
#define X0 0.25f
#define Y0 0.25f
#define X1 0.75f
#define Y1 0.75f

struct SceneEditorSettings{
    SceneEditorSettings(){
        relativeBoundingBox[0] = X0;
        relativeBoundingBox[1] = Y0;
        relativeBoundingBox[2] = X1;
        relativeBoundingBox[3] = Y1;
    }
    float relativeBoundingBox[4];
};