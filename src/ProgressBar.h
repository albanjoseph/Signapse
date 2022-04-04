#include "scene.h"

class ProgressBar{
public:
    ProgressBar();
    int get_progress(Scene s);
    void reset_progress();
protected:
    int threshold;
    int count;
};