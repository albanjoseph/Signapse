#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <queue>
#include "reel.h"
#include "camera.h"
#include "BlockingQueue.h"
#include "BlockingQueue.cpp"
using namespace cv;
using namespace std;

int main(int, char**)
{
    BlockingQueue<int> bq;
    bq.Put(5);
    bq.Put(6);
    bq.Put(7);
    bq.Put(8);
    cout << bq.Get() << "\n";
    cout << bq.Get() << "\n";
    cout << bq.Get() << "\n";
    cout << bq.Get() << "\n";
    cout << bq.Get() << "\n";

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
    //Scene val;
    //cout << val.task << endl;
    //while (!(waitKey(5) >= 0)){
    //    if (!(c.IsEmpty())){
    //        val = c.Pop();
    //    }
    //    cv::imshow("window", val.frame);
    //}

    //val = p.Pop();
    //val = c.Pop();
    //cout << val.task << endl;
    //val = p.Pop();
    //val = c.Pop();
    //cout << val.task << endl;
    return 0;
}