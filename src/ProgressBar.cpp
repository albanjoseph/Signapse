#include "ProgressBar.h"
#include <stdio.h>
#include "iostream"

ProgressBar::ProgressBar(){
    SetThreshold(100);
}

int ProgressBar::GetProgress(std::string result, std::string task){
    if(task == result){
        count++;
    }
    int progress = 100*count/threshold;
    return progress;
}

void ProgressBar::ResetProgress(){
    count = 0;
}

void ProgressBar::SetThreshold(int thres) {
    threshold = thres;
}