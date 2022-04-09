#include "ProgressBar.h"
#include <stdio.h>
#include "iostream"

ProgressBar::ProgressBar(){
    count = 0;
    threshold = 100;
}

int ProgressBar::get_progress(Scene s, std::string task){
    if(task == s.result){
        count++;
    }
    int progress = 100*count/threshold;
    return progress;
}

void ProgressBar::reset_progress(){
    count = 0;
}