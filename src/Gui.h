//
// Created by ross on 01/04/2022.
//

#ifndef SIGNAPSE_GUI_H
#define SIGNAPSE_GUI_H
#include <QCoreApplication>
#include "qtGenGui.h"
#include "stdlib.h"

#include <opencv2/core.hpp>
#include "opencv2/highgui/highgui.hpp"

#include "SignapseUtils.h"


#define testFolder "test/asl_alphabet_test/"

/*
 * A class to wrap the QT generated header file and handle GUI functionality
 */
class Gui {
public:
    Gui();
    void MakeVisible();
    void SetTargetImage(int target);
    void SetTargetImage(std::string target);

private:
    QMainWindow *widget;
    Ui_MainWindow *ui;
    void setDemoImage(cv::Mat img);
    void setTaskText(std::string letter);
};


#endif //SIGNAPSE_GUI_H
