//
// Created by ross on 01/04/2022.
//

#include "Gui.h"

#define UI_WDH 725
#define UI_HGT 448

Gui::Gui() {
    widget = new QMainWindow();
    widget->setFixedSize(UI_WDH, UI_HGT);
    ui = new Ui_MainWindow();
    ui->setupUi(widget);
}

void Gui::MakeVisible() {
    widget->setVisible(true);
    makeConnections();
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
    SetTargetImage(SignapseUtils::makeTask());
}

void Gui::makeConnections() {
    QObject::connect(ui->pushButton, &QPushButton::released, this, &Gui::ButtonPressed);
}




void Gui::setDemoImage(cv::Mat img) {
    ui->label_2->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));

}

void Gui::setTaskText(std::string letter){
    ui->listWidget->item(2)->setText(QCoreApplication::translate("MainWindow", letter.c_str(), nullptr));
}