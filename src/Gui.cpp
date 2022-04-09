#include "Gui.h"

#define UI_WDH 1000
#define UI_HGT 700

Gui::Gui() {
    widget = new QMainWindow();
    widget->setFixedSize(UI_WDH, UI_HGT);
    ui = new Ui_MainWindow();
    ui->setupUi(widget);
    SetTargetImage("A");
    makeConnections();
}

void Gui::NextScene(Scene next) {
    //flip frame
    if(next.result == "") {
        cv::Mat temp = next.frame;
        cv::flip(temp, next.frame, 1);
        QImage imgIn = QImage((uchar *) next.frame.data, next.frame.cols, next.frame.rows, next.frame.step,
                              QImage::Format_RGB888);
        ui->label->setPixmap(QPixmap::fromImage(imgIn));
        ui->label->resize(ui->label->pixmap()->size());
    }
    else{
        int progress = progress_bar.get_progress(next, currentTask);
        emit progressChanged(progress);
    }
    
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
    currentTask = new_task;
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

void Gui::SetTask(std::string newTask){
    currentTask = newTask;
}