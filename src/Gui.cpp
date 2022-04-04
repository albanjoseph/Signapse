//
// Created by ross on 01/04/2022.
//

#include "Gui.h"

#define UI_WDH 1000
#define UI_HGT 700

//virtual Gui::~Gui() {};

Gui::Gui() {
    widget = new QMainWindow();
    widget->setFixedSize(UI_WDH, UI_HGT);
    ui = new Ui_MainWindow();
    ui->setupUi(widget);
    SetTargetImage("A");
    makeConnections();
}

void Gui::nextScene(Scene next) {
    cv::Mat img = next.frame;
    QImage imgIn= QImage((uchar*) img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(imgIn));
    ui->label->resize(ui->label->pixmap()->size());
    int progress = progress_bar.get_progress(next, current_task);
    emit progressChanged(progress);
}

void Gui::SetVisible(bool visible) {
    widget->setVisible(visible);
}


void Gui::SetTargetImage(int target) {
    std::string letter = SignapseUtils::getLetterFromDigit(target);
    SetTargetImage(letter);
}

void Gui::SetTargetImage(std::string letter) {
    std::string impath = testFolder + letter + "_test.jpg";
    cv::Mat img = cv::imread(impath);
    setDemoImage(img);
    setTaskText(letter);
}
void Gui::ButtonPressed(){
    std::string new_task = SignapseUtils::getLetterFromDigit(SignapseUtils::makeTask());
    SetTargetImage(new_task);
    current_task = *new_task.c_str();
    progress_bar.reset_progress();
}

void Gui::makeConnections() {
    QObject::connect(ui->pushButton, &QPushButton::released, this, &Gui::ButtonPressed);
    QObject::connect(this, &Gui::progressChanged, ui->progressBar, &QProgressBar::setValue);
}

void Gui::setDemoImage(cv::Mat img) {
    cv::Mat rgb;
    cv::cvtColor(img, rgb, cv::COLOR_BGR2RGB);
    ui->label_2->setPixmap(QPixmap::fromImage(QImage(rgb.data, rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888)));
    ui->label_2->resize(ui->label_2->pixmap()->size());

}

void Gui::setTaskText(std::string letter){
    ui->listWidget->item(2)->setText(QCoreApplication::translate("MainWindow", letter.c_str(), nullptr));
}

void Gui::set_task(char new_task){
    current_task = new_task;
}