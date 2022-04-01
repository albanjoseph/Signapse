//
// Created by ross on 01/04/2022.
//

#ifndef SIGNAPSE_GUI_H
#define SIGNAPSE_GUI_H

#include "qtGenGui.h"
#include "stdlib.h"
#include <opencv2/core.hpp>

#define testFolder "test/asl_alphabet_test/"

/*
 * A class to wrap the QT generated header file and handle GUI functionality
 */
class Gui {
public:
    Gui(int argc, char **argv);
    void Start();
    void SetTargetImage(int target);
    void SetTargetImage(std::string target);

private:
    QApplication app;
    QMainWindow widget;
    Ui_MainWindow ui;
    void setLabel_2(cv::Mat img);
};


#endif //SIGNAPSE_GUI_H
