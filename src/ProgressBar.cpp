#include "ProgressBar.h"
#include <stdio.h>
#include "iostream"

ProgressBar::ProgressBar(){
    count = 0;
    threshold = 200;
}

int ProgressBar::get_progress(Scene s){
    printf("task=%c result=%c\n\r",s.task-32,*s.result.c_str());
    if(s.task-32 == *s.result.c_str()){
        count++;
        printf("progress=%i\n\r", count);
    }
    int progress = 100*count/threshold;
    return progress;
}

void ProgressBar::reset_progress(){
    count = 0;
}