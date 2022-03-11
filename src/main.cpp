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
#include "stdlib.h"
using namespace cv;
using namespace std;

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60
#define THRES 200

void printProgress(double percentage) {
    int val = (int) percentage;
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush(stdout);
}

//returns a random nr range [0-25]
int makeTask(){
    return rand() % 25;
}

cv::Mat drawBox(cv::Mat img, int box[4]){
    int x  = box[0]; int y = box[1];
    int width = box[2] - box[0]; int height = box[3] - box[1];
    cv::Rect rect(x, y, width, height);
    cv::rectangle(img, rect, cv::Scalar(0, 255, 0));
    return img;
}



int main(int, char**)
{
    //init rand seed
    srand (time(NULL));

    Camera c = Camera();
    c.setBoundingBox(0.25, 0.25, 0.75, 0.75);
    c.start_thread();
    CNNProcessor cnn = CNNProcessor(&c, "models/asl-mobilenetv2.pb");

    std::vector<std::string> results = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V",
                                        "W", "X", "Y", "Z", "del", "space", "nothing"};
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
    printf("   _____ _                                  \n"
           "  / ____(_)                                 \n"
           " | (___  _  __ _ _ __   __ _ _ __  ___  ___ \n"
           "  \\___ \\| |/ _` | '_ \\ / _` | '_ \\/ __|/ _ \\\n"
           "  ____) | | (_| | | | | (_| | |_) \\__ \\  __/\n"
           " |_____/|_|\\__, |_| |_|\\__,_| .__/|___/\\___|\n"
           "            __/ |           | |             \n"
           "           |___/            |_|    \n \nWelcome to Signapse, the tool for helping everyday people learn sign language for free!");
    do
    {
        cout << '\n' << "Press any key to continue...";
    } while (cin.get() != '\n');

    int task;
    char key;
    while(key != 'q'){
        task = makeTask();
        printf("Current task is: %d \n", task);
        printf("Enter \"y\" to confirm, \"q\" to quit, or any other key to change task... ");
        key = cin.get();
        if(key == 'y'){
            printf("\n Task confirmed. Progress...");
            double progress = 0.0;
            float nr_correct = 0;
            while ((!(waitKey(5) >= 0)) && (progress < 100)){
                cnn.SelfPush();
                val_cnn = cnn.Pop();
                cv::Mat blob = cnn.MakeBlob(val_cnn);
                
                int result = cnn.Inference(val_cnn);
                if(result == task){
                    nr_correct++;
                    progress = (nr_correct / THRES) * 100;
                }
                cv::Mat boxFrame = drawBox(val_cnn.frame, val_cnn.regionOfInterest);
                cv::imshow("window2", boxFrame);

                printProgress(progress);
            }


        }

    }
    return 0;
}

