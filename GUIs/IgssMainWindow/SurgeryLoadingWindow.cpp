#include "SurgeryLoadingWindow.h"

SurgeryLoadingWindow::SurgeryLoadingWindow():QWidget()
{
    this->constructIHM();
    //this->displaySurgeryLoadingWindow();
}

void SurgeryLoadingWindow::constructIHM(){

    this->surgeryLoadingItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->surgeryLoadingSliderBar =new QSlider(Qt::Horizontal);
    this->surgeryLoadingSliderBar->setFixedHeight(50);
    this->surgeryLoadingSliderBar->setStyleSheet("QSlider::groove:horizontal{border: 1px solid #bbb;background:white;height:50px;border-radius: 20px;}"
                                                 "QSlider::sub-page:horizontal {background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop: 0 #66e, stop: 1 #bbf);background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,stop: 0 #bbf, stop: 1 #55f);border: 1px solid #777;height: 50px;border-radius: 20px;}"
                                                 "QSlider::add-page:horizontal {background: #fff;border: 1px solid #777;height: 50px;border-radius: 4px;}QSlider::handle:horizontal {background: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #eee, stop:1 #ccc);border: 1px solid #777;width: 13px;margin-top: -2px;margin-bottom: -2px;border-radius: 4px;}"
                                                 "QSlider::handle:horizontal:hover {background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #fff, stop:1 #ddd);border: 1px solid #444;border-radius: 4px;}QSlider::sub-page:horizontal:disabled {background: #bbb;border-color: #999;}"
                                                 "QSlider::add-page:horizontal:disabled {background: #eee;border-color: #999;}"
                                                 "QSlider::handle:horizontal:disabled {background: #eee;border: 1px solid #aaa;border-radius: 20px;}");
    this->surgeryLoadingSliderBar->setMinimum(0);
    this->surgeryLoadingSliderBar->setMaximum(100);
    this->surgeryLoadingWidgetLayout = new QVBoxLayout(this);
    this->surgeryLoadingWidgetLayout->addItem(this->surgeryLoadingItem);
    this->surgeryLoadingWidgetLayout->addWidget(surgeryLoadingSliderBar);
}

void SurgeryLoadingWindow::displaySurgeryLoadingWindow(){
    this->showFullScreen();
}


