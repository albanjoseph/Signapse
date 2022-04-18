#ifndef SIGNAPSE_SIGNAPSEUTILS_H
#define SIGNAPSE_SIGNAPSEUTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "iostream"
#include "SignapseUtils.h"

#define MODEL_PATH "models/asl-mobilenetv2.pb"
#define NR_TASKS 26
namespace {
/*!
 * Simple static class for some utilities needed by Signapse objects.
 */
    class SignapseUtils {
    public:
        /*!
         * Array of ordered results from expected at the output of the current CNN model in use.
         */
        static std::vector <std::string> results;
        
        /*!
         * Prints welcome message and ASCII art logo
         */
        static void welcomeMessage() {
            printf("   _____ _                                  \n"
                   "  / ____(_)                                 \n"
                   " | (___  _  __ _ _ __   __ _ _ __  ___  ___ \n"
                   "  \\___ \\| |/ _` | '_ \\ / _` | '_ \\/ __|/ _ \\\n"
                   "  ____) | | (_| | | | | (_| | |_) \\__ \\  __/\n"
                   " |_____/|_|\\__, |_| |_|\\__,_| .__/|___/\\___|\n"
                   "            __/ |           | |             \n"
                   "           |___/            |_|    \n \nWelcome to Signapse, the tool for helping everyday people learn sign language for free!\n");
        }
        /*!
         * Used to convert an integer index result into a string sign
         * @param digit integer index
         * @return std::string representing sign at given index
         */
        static std::string getLetterFromDigit(int digit) {
            return results[digit % results.size()];
        }
        /*!
         * Generates a random sign for use assigning tasks to users.
         *
         */
        static std::string makeTask() {
            int task_int = rand() % NR_TASKS;
            return getLetterFromDigit(task_int);
        }
        /*!
         * Sets the random seed to current system time.
         *
         */
        static void randSeed(){
            srand((unsigned) time(NULL));
        }
        /*!
         * @return Path of the currently used CNN network. Path given as std::string
         */
        static std::string getModelPath() {
            return MODEL_PATH;
        }
    };
    /*!
     * Declares results array, this may be changed for different CNN output results.
     */
    std::vector <std::string> SignapseUtils::results = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                                                        "N", "O", "P", "Q", "R", "S", "T", "U", "V",
                                                        "W", "X", "Y", "Z", "del", "space", "nothing"};
}

#endif
