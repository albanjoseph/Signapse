#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <queue>
#include "reel.h"
#include "camera.h"
#include "CNNProcessor.h"
using namespace cv;
using namespace std;

cv::Mat drawBox(cv::Mat img, int box[4]){
    int x  = box[0]; int y = box[1];
    int width = box[2] - box[0]; int height = box[3] - box[1];
    cv::Rect rect(x, y, width, height);
    cv::rectangle(img, rect, cv::Scalar(0, 255, 0));
    return img;
}

int main(int, char**)
{
    Camera c = Camera();
    c.setBoundingBox(0.25, 0.25, 0.75, 0.75);
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
        cv::Mat boxFrame = drawBox(val_cnn.frame, val_cnn.regionOfInterest);
        cv::imshow("window2", boxFrame)
    }

    //val = p.Pop();
    //val = c.Pop();
    //cout << val.task << endl;
    //val = p.Pop();
    //val = c.Pop();
    //cout << val.task << endl;
    return 0;
}

