#include "ProgressBar.h"
#include <stdio.h>
#include "iostream"

ProgressBar::ProgressBar(){
    count = 0;
    threshold = 200;
}

int ProgressBar::get_progress(Scene s){
    //printf("%i\n\r",count);
    if(s.task == *s.result.c_str()){
        count++;
    }
    int progress = 100*count/threshold;
    return progress;
}

void ProgressBar::reset_progress(){
    count = 0;
}