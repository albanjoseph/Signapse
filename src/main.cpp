#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <queue>
#include "reel.h"
#include "camera.h"
#include "CNNProcessor.h"
using namespace cv;
using namespace std;

int main(int, char**)
{
    Camera c = Camera();

    c.start_thread();
    CNNProcessor cnn = CNNProcessor(&c);

//    BlockingQueue<int> bq;
//    bq.Push(5);
//    bq.Push(6);
//    bq.Push(7);
//    bq.Push(8);
//    cout << bq.Pop() << "\n";
//    cout << bq.Pop() << "\n";
//    cout << bq.Pop() << "\n";
//    cout << bq.Pop() << "\n";
//    cout << bq.Pop() << "\n";

    //Camera c = Camera();
    //c.Populate();
    //c.start_thread();

    /*
    c.set_current_task('h');
    c.Populate();
    c.set_current_task('y');
    c.Populate();
    */
    //CNNProcessor p = CNNProcessor(c);
    //p.SelfPush();
    //p.SelfPush();
    //p.SelfPush();
    //c.Stream();
    Scene val_cnn;
    Scene val_camera;
    while (!(waitKey(5) >= 0)){
        val_camera = c.Pop();
        cnn.SelfPush();
        val_cnn = cnn.Pop();
        cv::imshow("window", val_camera.frame);
        cv::imshow("window2", val_cnn.frame);
    }

    //val = p.Pop();
    //val = c.Pop();
    //cout << val.task << endl;
    //val = p.Pop();
    //val = c.Pop();
    //cout << val.task << endl;
    return 0;
}