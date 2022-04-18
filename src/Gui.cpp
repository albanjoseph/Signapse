#include "Gui.h"

#define UI_WDH 1000
#define UI_HGT 700

/*!
 * Constructor sets up GUI, makes signal connections
 * @param win points to QMainWindow from main thread
 * @param ui_win points to Ui_MainWindow from main thread
 */
Gui::Gui(QMainWindow* win, Ui_MainWindow* ui_win) {
    widget = win;
    widget->setFixedSize(UI_WDH, UI_HGT);
    ui = ui_win;
    ui->setupUi(widget);
    SetTask("A");
    makeConnections();
    SignapseUtils::randSeed();
}
/*!
 * Handles the next scene from the video processing pipeline. If the result is empty, the viewing pane is updated, otherwise, the progress bar is updated.
 * @param next The Scene to be processed
 */
void Gui::NextScene(Scene next) {
    //flip frame
    if(next.result == "") {
        cv::Mat temp;
        cv::flip(next.frame, temp, 1);
        QImage imgIn = QImage((uchar *) temp.data, temp.cols, temp.rows, temp.step,
                              QImage::Format_RGB888);
        ui->label->setPixmap(QPixmap::fromImage(imgIn));
        ui->label->resize(ui->label->pixmap()->size());
    }
    else{
        int progress = progressBar.GetProgress(next.result, currentTask);
        emit progressChanged(progress);
        if(progress >= 100){
            buttonPressed();
        }
    }
    
}
/*!
 * Sets underlying widget visibility.
 * @param visible
 */
void Gui::SetVisible(bool visible) {
    widget->setVisible(visible);
}
/*!
 * Sets the target to match with user sign
 * @param letter string represenation of the target sign
 */
void Gui::SetTargetImage(std::string letter) {
    std::string impath = testFolder + letter + "_test.jpg";
    cv::Mat img = cv::imread(impath);
    setDemoImage(img);
    setTaskText(letter);
}
/*!
 * Method handler for when the next task button is pressed, sets new task and resets the progress bar.
 */
void Gui::buttonPressed(){
    std::string new_task = SignapseUtils::makeTask();
    SetTargetImage(new_task);
    currentTask = new_task;
    progressBar.ResetProgress();
}

void Gui::updateThreshold(){
    progressBar.SetThreshold(ui->spinBox->value());
    progressBar.ResetProgress();
}

/*!
 * Makes signal connections for the GUI interrupts.
 */
void Gui::makeConnections() {
    QObject::connect(ui->pushButton, &QPushButton::released, this, &Gui::buttonPressed);
    QObject::connect(this, &Gui::progressChanged, ui->progressBar, &QProgressBar::setValue);
    QObject::connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &Gui::updateThreshold);
}


void Gui::setDemoImage(cv::Mat img) {
    cv::Mat rgb;
    cv::cvtColor(img, rgb, cv::COLOR_BGR2RGB);
    cv::Mat flip;
    cv::flip(rgb, flip, 1);
    ui->label_2->setPixmap(QPixmap::fromImage(QImage(flip.data, flip.cols, flip.rows, flip.step, QImage::Format_RGB888)));
    ui->label_2->resize(ui->label_2->pixmap()->size());

}

void Gui::setTaskText(std::string letter){
    ui->listWidget->item(2)->setText(QCoreApplication::translate("MainWindow", letter.c_str(), nullptr));
}

void Gui::SetTask(std::string newTask){
    currentTask = newTask;
    SetTargetImage("A");
}