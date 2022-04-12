#ifndef SIGNAPSE_GUI_H
#define SIGNAPSE_GUI_H

#include <QCoreApplication>
#include "QtGeneratedGui.h"
#include "stdlib.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

#include "ProgressBar.h"
#include "SignapseUtils.h"
#include "SceneCallback.h"

#define testFolder "test/asl_alphabet_test/"

/*
 * A class to wrap the QT generated header file and handle GUI functionality
 */
class Gui : public QWidget, public SceneCallback{
    Q_OBJECT
public:
    virtual void NextScene(Scene next);
    Gui();
    void SetVisible(bool visible);
    void SetTargetImage(int target);
    void SetTargetImage(std::string target);
    void ButtonPressed();
    void SetTask(std::string newTask);

private:
    QMainWindow *widget;
    Ui_MainWindow *ui;
    ProgressBar progress_bar;
    void setDemoImage(cv::Mat img);
    void setTaskText(std::string letter);
    void makeConnections();
    std::string currentTask;
signals:
    void progressChanged(int progress);
};

#endif
