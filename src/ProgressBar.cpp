#include "ProgressBar.h"
#include <stdio.h>
#include "iostream"

ProgressBar::ProgressBar(){
    count = 0;
    threshold = 100;
}

int ProgressBar::get_progress(std::string result, std::string task){
    if(task == result){
        count++;
    }
    int progress = 100*count/threshold;
    return progress;
}

void ProgressBar::reset_progress(){
    count = 0;
}