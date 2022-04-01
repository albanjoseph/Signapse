//
// Created by ross on 01/04/2022.
//

#include "Gui.h"

Gui::Gui(int argc, char **argv) {
    app(argc, argv);
    ui.setupUi(&widget);
}

void Gui::Start() {
    widget.show();
    return app.exec();
}
void Gui::SetTargetImage(int target) {
    impath = testFolder + SignapseUtils::getLetterFromDigit(target) + "_test.jpg";
    img = cv2::imread(impath);
    setLabel_2(img);
}

void Gui::SetTargetImage(std::string target) {
    impath = testFolder + target + "_test.jpg";
    img = cv2::imread(impath);
    setLabel_2(img);
}



void Gui::setLabel_2(cv::Mat img) {
    ui.label_2->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}
