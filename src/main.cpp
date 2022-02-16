// CPP code to illustrate Queue in
// Standard Template Library (STL)
#include <iostream>
#include <queue>
#include "reel.h"
#include "camera.h"
#include "CNNProcessor.h"

using namespace std;

int main()
{
    Camera c = Camera();
    c.Populate();
    c.set_current_task('y');
    c.Populate();
    CNNProcessor p = CNNProcessor(c);
    p.SelfPush();
    p.SelfPush();
    p.SelfPush();

    Scene val = p.Pop();
    cout << val.task << endl;
    val = p.Pop();
    cout << val.task << endl;
    val = p.Pop();
    cout << val.task << endl;
    return 0;
}
