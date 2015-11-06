#include "AlgorithmTestPlatform.h"

AlgorithmTestPlatform::AlgorithmTestPlatform(SystemDispatcher* dispatcher,
                                             QFont *caracterStyle,
                                             int appWidth,
                                             int appHeight)
{
    this->dispatcher = dispatcher;
    this->caracterStyle = caracterStyle;
    this->appWidth = appWidth;
    this->appHeight = appHeight;
    this->setFixedHeight(this->appHeight*0.18);
    this->setFont(*this->caracterStyle);
    this->initVariable();
    this->constructIHM();
    this->setConnections();
}

//!
//! \brief AlgorithmTestPlatform::initVariable
//!
void AlgorithmTestPlatform::initVariable(){
    this->labelStyleSheet = "border: 1px solid aliceBlue;border-radius: 5px;padding: 2 2px;background-color: transparent; color: AliceBlue";
    this->sliderStyleSheet = "QSlider::groove:horizontal{border: 1px solid #bbb;background:white;height:50px;border-radius: 20px;}"
                             "QSlider::sub-page:horizontal {background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop: 0 #66e, stop: 1 #bbf);background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,stop: 0 #bbf, stop: 1 #55f);border: 1px solid #777;height: 50px;border-radius: 20px;}"
                             "QSlider::add-page:horizontal {background: #fff;border: 1px solid #777;height: 50px;border-radius: 4px;}QSlider::handle:horizontal {background: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #eee, stop:1 #ccc);border: 1px solid #777;width: 13px;margin-top: -2px;margin-bottom: -2px;border-radius: 4px;}"
                             "QSlider::handle:horizontal:hover {background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #fff, stop:1 #ddd);border: 1px solid #444;border-radius: 4px;}QSlider::sub-page:horizontal:disabled {background: #bbb;border-color: #999;}"
                             "QSlider::add-page:horizontal:disabled {background: #eee;border-color: #999;}"
                             "QSlider::handle:horizontal:disabled {background: #eee;border: 1px solid #aaa;border-radius: 20px;}";
}

//!
//! \brief AlgorithmTestPlatform::constructIHM
//!
void AlgorithmTestPlatform::constructIHM(){

    this->cpuLabel = new QLabel("CPU");
    this->cpuLabel->setFont(*this->caracterStyle);
    this->cpuLabel->setStyleSheet(this->labelStyleSheet);
    this->cpuLabel->setAlignment(Qt::AlignCenter);
    this->ramLabel = new QLabel("RAM");
    this->ramLabel->setFont(*this->caracterStyle);
    this->ramLabel->setStyleSheet(this->labelStyleSheet);
    this->ramLabel->setAlignment(Qt::AlignCenter);
    this->diskLable = new QLabel("Disk");
    this->diskLable->setFont(*this->caracterStyle);
    this->diskLable->setStyleSheet(this->labelStyleSheet);
    this->diskLable->setAlignment(Qt::AlignCenter);
    this->netLable = new QLabel("Net");
    this->netLable->setFont(*this->caracterStyle);
    this->netLable->setStyleSheet(this->labelStyleSheet);
    this->netLable->setAlignment(Qt::AlignCenter);

    this->cpuSlider = new QSlider(Qt::Horizontal);
    this->cpuSlider->setFixedHeight(10);
    this->cpuSlider->setStyleSheet(this->sliderStyleSheet);
    this->cpuSlider->setMinimum(0);
    this->cpuSlider->setMaximum(100);
    this->ramSlider = new QSlider(Qt::Horizontal);
    this->ramSlider->setFixedHeight(10);
    this->ramSlider->setStyleSheet(this->sliderStyleSheet);
    this->ramSlider->setMinimum(0);
    this->ramSlider->setMaximum(100);
    this->diskSlider = new QSlider(Qt::Horizontal);
    this->diskSlider->setFixedHeight(10);
    this->diskSlider->setStyleSheet(this->sliderStyleSheet);
    this->diskSlider->setMinimum(0);
    this->diskSlider->setMaximum(100);
    this->netSlider = new QSlider(Qt::Horizontal);
    this->netSlider->setFixedHeight(10);
    this->netSlider->setStyleSheet(this->sliderStyleSheet);
    this->netSlider->setMinimum(0);
    this->netSlider->setMaximum(100);

    this->cpuRateLabel = new QLabel();
    this->ramRateLabel = new QLabel();
    this->diskRateLable = new QLabel();
    this->netRateLable = new QLabel();

    this->systemUsageStatusWidget = new QLabel();
    this->systemUsageStatusWidget->setStyleSheet(this->labelStyleSheet);
    this->systemUsageStatusWidget->setFixedWidth(this->appWidth*0.13);
    this->systemUsageStatusLayout = new QGridLayout(this->systemUsageStatusWidget);
    this->systemUsageStatusLayout->addWidget(this->cpuLabel, 0 , 0);
    this->systemUsageStatusLayout->addWidget(this->ramLabel, 1 , 0);
    this->systemUsageStatusLayout->addWidget(this->diskLable, 2 , 0);
    this->systemUsageStatusLayout->addWidget(this->netLable, 3 , 0);

    this->systemUsageStatusLayout->addWidget(this->cpuSlider, 0, 1);
    this->systemUsageStatusLayout->addWidget(this->ramSlider, 1 , 1);
    this->systemUsageStatusLayout->addWidget(this->diskSlider, 2 , 1);
    this->systemUsageStatusLayout->addWidget(this->netSlider, 3 , 1);

    this->systemUsageStatusLayout->addWidget(this->cpuRateLabel, 0 , 2);
    this->systemUsageStatusLayout->addWidget(this->ramRateLabel, 1 , 2);
    this->systemUsageStatusLayout->addWidget(this->diskRateLable, 2 , 2);
    this->systemUsageStatusLayout->addWidget(this->netRateLable, 3 , 2);

    terminalWindow = new QWidget();
    terminalWindowLayout = new QVBoxLayout(terminalWindow);

    systemStatus = new QTextEdit();
    systemStatus->setFont(*this->caracterStyle);
    systemStatus->setStyleSheet("border: 1px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue");

    systemCommand = new QLineEdit();
    systemCommand->setFont(*this->caracterStyle);
    systemCommand->setStyleSheet("border: 1px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue");

    terminalWindowLayout->addWidget(systemStatus);
    terminalWindowLayout->addWidget(systemCommand);
    terminalWindowLayout->setSpacing(2);
    terminalWindowLayout->setMargin(0);

    platformLayout = new QHBoxLayout(this);
    platformLayout->addWidget(systemUsageStatusWidget);
    platformLayout->addWidget(terminalWindow);
    platformLayout->setSpacing(2);
    platformLayout->setMargin(0);
}

void AlgorithmTestPlatform::setConnections(){
    this->connect(systemCommand,SIGNAL(returnPressed()),this,SLOT(doParseCommand()));
}

void AlgorithmTestPlatform::setSystemStatus(QString status){
    this->systemStatus->setText(status);
}

//!----------------------------------------------------------------------------------------
//!
//! \brief AlgorithmTestPlatform::doParseCommand
//!
void AlgorithmTestPlatform::doParseCommand(){

    QString cmd = systemCommand->text();
    setSystemStatus(cmd);
    QString msg;

    if(cmd.contains("vef")){
        if(cmd.contains("mri")){
            QStringList temp = cmd.split(" mri ");
            int id = temp[1].toInt(0,10);
            msg = this->dispatcher->doImageProcessingByMethodType(id, 3, "vef");
        }
        else{
            //!do 2d vessel enhancement
        }
        this->setSystemStatus(msg);
    }
    else if(cmd.contains("check")){
        if(cmd.contains("mri")){
            if(cmd.contains("states")){
                this->getPatientsStatus();
            }
        }
    }
}

//!----------------------------------------------------------------------------------------
//!doParseCommand
//! \brief AlgorithmTestPlatform::getPatientsStatus
//!
void AlgorithmTestPlatform::getPatientsStatus(){
    QStringList s = this->dispatcher->getPatientsStatus();
    QString info = "";
    for(int i = 0; i < s.length(); i++){
        info += s[i]+"\n";
    }
    this->setSystemStatus(info);
}

