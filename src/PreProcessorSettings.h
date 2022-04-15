
#define X0 0.25f
#define Y0 0.25f
#define X1 0.75f
#define Y1 0.75f
/*!
 * A simple struct to add some default settings for PreProcessor
 */
struct PreProcessorSettings{
    PreProcessorSettings(){
        relativeBoundingBox[0] = X0;
        relativeBoundingBox[1] = Y0;
        relativeBoundingBox[2] = X1;
        relativeBoundingBox[3] = Y1;
    }
    PreProcessorSettings(const PreProcessorSettings& cpy){
        relativeBoundingBox[0] = cpy.relativeBoundingBox[0];
        relativeBoundingBox[1] = cpy.relativeBoundingBox[1];
        relativeBoundingBox[2] = cpy.relativeBoundingBox[2];
        relativeBoundingBox[3] = cpy.relativeBoundingBox[3];
    }
    float relativeBoundingBox[4];
};