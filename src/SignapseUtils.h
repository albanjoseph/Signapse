#ifndef SIGNAPSE_SIGNAPSEUTILS_H
#define SIGNAPSE_SIGNAPSEUTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "iostream"
#include "SignapseUtils.h"

#define MODEL_PATH "models/asl-mobilenetv2.pb"


class SignapseUtils {
public:
    static std::string getLetterFromDigit(int digit){
        std::string results[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V",
                                 "W", "X", "Y", "Z", "del", "space", "nothing"};
        return results[digit];
    }
    static void welcomeMessage(){
        printf("   _____ _                                  \n"
               "  / ____(_)                                 \n"
               " | (___  _  __ _ _ __   __ _ _ __  ___  ___ \n"
               "  \\___ \\| |/ _` | '_ \\ / _` | '_ \\/ __|/ _ \\\n"
               "  ____) | | (_| | | | | (_| | |_) \\__ \\  __/\n"
               " |_____/|_|\\__, |_| |_|\\__,_| .__/|___/\\___|\n"
               "            __/ |           | |             \n"
               "           |___/            |_|    \n \nWelcome to Signapse, the tool for helping everyday people learn sign language for free!");
    }


    static void printProgress(float percentage, int prediction) {
        std::string letter = getLetterFromDigit(prediction);
        std::cout << "\r Prediction: " << letter << ", Progress: " << percentage << "% - keep signing!            ";
        fflush(stdout);
    }

    static int makeTask(){
        srand( (unsigned)time( NULL ) );
        return rand() % 25;
    }

    static std::string getModelPath(){
        return MODEL_PATH;
    }
};


#endif
