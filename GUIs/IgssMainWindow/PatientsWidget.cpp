#include "PatientsWidget.h"

PatientsWidget::PatientsWidget(SystemDispatcher* dispatcher,
                               AlgorithmTestPlatform *algorithmTestPlatform,
                               SurgeryPlanWindow* surgeryPlanWindow,
                               PatientInformationWidget* patientInformationWidget,
                               GuidewareTrackingWindow* guidewareTrackingWindow,
                               QTime* surgeryTimer,
                               QFont *caracterStyle,
                               int appWidth,
                               int appHeight) : QWidget(){

    this->dispatcher = dispatcher;
    this->algorithmTestPlatform = algorithmTestPlatform;
    this->surgeryPlanWindow = surgeryPlanWindow;
    this->patientInformationWidget = patientInformationWidget;
    this->guidewareTrackingWindow = guidewareTrackingWindow;
    this->surgeryTimer = surgeryTimer;
    this->caracterStyle = caracterStyle;
    this->appWidth = appWidth;
    this->appHeight = appHeight;

    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->setFocusPolicy(Qt::StrongFocus);
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::displayLastFiveOrLess
//!
void PatientsWidget::displayLastFiveOrLess(){
    for(int cpt = 5; cpt > 0; cpt--){
           waitingPatientsQueue.at(numberOfPatient - cpt)->setPixmap(waitingPatientsPhotoStringQueue.at(numberOfPatient - cpt));
           waitingPatientsQueue.at(numberOfPatient - cpt)->setAutoFillBackground(true);
           waitingPatientsQueue.at(numberOfPatient - cpt)->setScaledContents(true);
           waitingPatientsQueue.at(numberOfPatient - cpt)->update();

           waitingPatientsNameQueue.at(numberOfPatient - cpt)->setText(waitingPatientsStringNameQueue.at(numberOfPatient - cpt));
           waitingPatientsNameQueue.at(numberOfPatient - cpt)->setAutoFillBackground(true);
           waitingPatientsNameQueue.at(numberOfPatient - cpt)->setScaledContents(true);
           waitingPatientsNameQueue.at(numberOfPatient - cpt)->update();
      }
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::displayCurrentPatinetInfo
//!
void PatientsWidget::displayCurrentPatinetInfo(){
    this->nameLineEdit->setText(waitingPatientsStringNameQueue.at(numberOfPatient - 1));
    this->birthdayLineEdit->setText(currentPatinetInfoQueue.at(0));
    //this->sexualLineEdit->setText(currentPatinetInfoQueue.at(1));
    //this->idNumberEdit->setText(currentPatinetInfoQueue.at(1));
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::findPatientExisted
//!
void PatientsWidget::findPatientExisted(){
     numberOfPatient = this->dispatcher->findPatientExisted();

    //algorithmTestPlatform->setSystemStatus(QString::number(numberOfPatient));

    for(int cpt = 5; cpt > 0; cpt--){
       waitingPatientsPhotoStringQueue.append(this->dispatcher->getPatientById(numberOfPatient - cpt)->getPhotoPath());
       waitingPatientsStringNameQueue.append(this->dispatcher->getPatientById(numberOfPatient - cpt)->getName());
       waitingPatientsIDQueue.append(QString::number(numberOfPatient - cpt));
    }
    currentPatinetInfoQueue.append(this->dispatcher->getPatientById(numberOfPatient - 1)->getBirthdayOfPatient());
    //currentPatinetInfoQueue.append(this->dispatcher->getPatientById(numberOfPatient - 1)->getSexOfPatient());
    //currentPatinetInfoQueue.append(this->dispatcher->getPatientById(numberOfPatient - 1)->getIdNumber());

    this->displayLastFiveOrLess();
    this->displayCurrentPatinetInfo();
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::initVariable
//!
void PatientsWidget::initVariable(){
    this->surgeryLaunched = false;
    this->surgeryTerminated = true;
    this->numberOfPatient  = 0;
    this->dicomCDRomReader = new DicomCDRomReader();
    this->labelStyleSheet = "border: 1px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue";
    this->surgeryLoadingWindow = new SurgeryLoadingWindow();
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::setConnections
//!
void PatientsWidget::setConnections(){
    this->connect(this->cdRomParseButton, SIGNAL(clicked()), this, SLOT(doParseCdRom()));
    this->connect(this->surgeryLaunchButton, SIGNAL(clicked()), this, SLOT(launchSurgery()));
    this->connect(this->addPatientButton, SIGNAL(clicked()), this, SLOT(addPatient()));
    this->connect(this->leftSelectButton, SIGNAL(clicked()), this, SLOT(doLeftSelect()));
    this->connect(this->rightSelectButton, SIGNAL(clicked()), this, SLOT(doRightSelect()));
    this->connect(this->surgeryTerminateButton, SIGNAL(clicked()), this, SLOT(terminateSurgery()));
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::launchSurgery
//!
void PatientsWidget::launchSurgery(){

    //! ......
    this->surgeryLaunchButton->setFixedSize(0,0);
    this->surgeryTerminateButton->setFixedSize(this->appWidth*0.857*0.15,this->appHeight*0.857*0.15*0.3);
    this->surgeryLaunchButton->setEnabled(false);
    this->leftSelectButton->setEnabled(false);
    this->rightSelectButton->setEnabled(false);

    //! -----------------------------------------
    //!TODO: loading tasks execute......
    this->surgeryLoadingWindow->displaySurgeryLoadingWindow();

    //! -----------------------------------------

    this->surgeryPlanWindow->setPatientHandling(this->dispatcher->getPatientById(waitingPatientsIDQueue[numberOfPatient-1].toInt(0,10)));
    this->surgeryPlanWindow->update();

    //! -----------------------------------------
    //! loading task terminated......
    this->surgeryLoadingWindow->close();
    //!-----------------------------------------

    this->surgeryPlanWindow->displayWindow();
    this->guidewareTrackingWindow->displayWindow();

    this->surgeryLaunched = true;

    this->surgeryTimer->start();
    this->surgeryPlanWindow->setStartTime(this->surgeryTimer->elapsed());


}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::terminateSurgery
//!
void PatientsWidget::terminateSurgery(){
    if (!(QMessageBox::information(this,tr("Igss Surgery"),tr("Do you really want to terminate the surgery?"),tr("Yes"),tr("No")))){
        this->surgeryTerminateButton->setFixedSize(0,0);
        this->surgeryLaunchButton->setFixedSize(this->appWidth*0.857*0.15,this->appHeight*0.857*0.15*0.3);
        this->surgeryLaunchButton->setEnabled(true);
        this->leftSelectButton->setEnabled(true);
        this->rightSelectButton->setEnabled(true);
        this->surgeryLaunched = false;
        this->surgeryTerminated = true;
        this->surgeryPlanWindow->close();
        this->guidewareTrackingWindow->close();
        }
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::doLeftSelect
//!
void PatientsWidget::doLeftSelect(){
    if(this->surgeryLaunched){
        return;
    }

    if(this->surgeryTerminated){
    QString temp;
    temp = this->waitingPatientsPhotoStringQueue.at(0);
    this->waitingPatientsPhotoStringQueue.pop_front();
    this->waitingPatientsPhotoStringQueue.append(temp);

    QString temp1;
    temp1 = this->waitingPatientsStringNameQueue.at(0);
    this->waitingPatientsStringNameQueue.pop_front();
    this->waitingPatientsStringNameQueue.append(temp1);

    this->displayLastFiveOrLess();
    this->displayCurrentPatinetInfo();
    }

}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::doRightSelect
//!
void PatientsWidget::doRightSelect(){
    if(this->surgeryLaunched){
        return;
    }
    if(this->surgeryTerminated){
    QString temp;
    temp = this->waitingPatientsPhotoStringQueue.at(4);
    this->waitingPatientsPhotoStringQueue.pop_back();
    this->waitingPatientsPhotoStringQueue.insert(0,temp);

    QString temp1;
    temp1 = this->waitingPatientsStringNameQueue.at(4);
    this->waitingPatientsStringNameQueue.pop_back();
    this->waitingPatientsStringNameQueue.insert(0,temp1);

    this->displayLastFiveOrLess();
    this->displayCurrentPatinetInfo();
    }
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::doParseCdRom
//!
void PatientsWidget::doParseCdRom(){
    this->algorithmTestPlatform->setSystemStatus("doParseCdRom");

    //TODO
    //dicomCDRomReader->doParseCDRom(.......);


}
//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::addPatient
//!
void PatientsWidget::addPatient(){
    this->patientInformationWidget->display(QCursor::pos());
}

int PatientsWidget::testX(){
    return firstPatientPhotoWidget->width();
}

int PatientsWidget::testY(){
    return firstPatientPhotoWidget->height();
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::constructIHM
//!
void PatientsWidget::constructIHM(){
    this->waittingPatientsAndBlackAreaWindow = new QWidget();

    this->upBlackArea = new QWidget();
    this->upBlackArea->setFixedHeight(this->appHeight*0.185*0.1);
    this->upBlackArea->setStyleSheet("background-color:transparent");

    this->waittingPatientPhotoes = new QWidget();
    this->downBlackArea = new QWidget();
    this->downBlackArea->setFixedHeight(this->appHeight*0.857*0.15*0.3);

    this->leftBlackArea = new QWidget();
    this->leftBlackArea->setFixedWidth(this->appWidth*0.34*0.02);
    this->leftBlackArea->setStyleSheet("background-color:transparent");

    this->firstPatientPhotoWidget = new QWidget();
    this->firstPatientPhotoWidget->setFixedSize(this->appWidth*0.067, this->appHeight*0.166);
    this->firstPatientPhotoWidgetLayout = new QVBoxLayout(firstPatientPhotoWidget);
    this->firstPatientInfo = new QLabel();
    this->firstPatientInfo->setFont(*this->caracterStyle);
    this->firstPatientInfo->setStyleSheet(this->labelStyleSheet);
    this->firstPatientInfo->setFixedHeight(this->appHeight*0.028);
    this->firstPatientInfo->setAlignment(Qt::AlignCenter);

    this->firstPatientPhoto = new QLabel();
    this->firstPatientPhoto->setStyleSheet(this->labelStyleSheet);

    this->firstPatientPhotoWidgetLayout->addWidget(firstPatientPhoto);
    this->firstPatientPhotoWidgetLayout->addWidget(firstPatientInfo);

    this->secondPatientPhotoWidget = new QWidget();
    this->secondPatientPhotoWidget->setFixedSize(this->appWidth*0.067, this->appHeight*0.166);
    this->secondPatientPhotoWidgetLayout = new QVBoxLayout(secondPatientPhotoWidget);
    this->secondPatientInfo = new QLabel();
    this->secondPatientInfo->setFont(*this->caracterStyle);
    this->secondPatientInfo->setStyleSheet(this->labelStyleSheet);
    this->secondPatientInfo->setFixedHeight(this->appHeight*0.028);
    this->secondPatientInfo->setAlignment(Qt::AlignCenter);

    this->secondPatientPhoto = new QLabel();
    this->secondPatientPhoto->setStyleSheet(this->labelStyleSheet);

    this->secondPatientPhotoWidgetLayout->addWidget(secondPatientPhoto);
    this->secondPatientPhotoWidgetLayout->addWidget(secondPatientInfo);

    this->thirdPatientPhotoWidget = new QWidget();
    this->thirdPatientPhotoWidget->setFixedSize(this->appWidth*0.067, this->appHeight*0.166);
    this->thirdPatientPhotoWidgetLayout = new QVBoxLayout(thirdPatientPhotoWidget);
    this->thirdPatientInfo = new QLabel();
    this->thirdPatientInfo->setFont(*this->caracterStyle);
    this->thirdPatientInfo->setStyleSheet(this->labelStyleSheet);
    this->thirdPatientInfo->setFixedHeight(this->appHeight*0.028);
    this->thirdPatientInfo->setAlignment(Qt::AlignCenter);

    this->thirdPatientPhoto = new QLabel();
    this->thirdPatientPhoto->setStyleSheet(this->labelStyleSheet);

    this->thirdPatientPhotoWidgetLayout->addWidget(thirdPatientPhoto);
    this->thirdPatientPhotoWidgetLayout->addWidget(thirdPatientInfo);

    this->fourthPatientPhotoWidget = new QWidget();
    this->fourthPatientPhotoWidget->setFixedSize(this->appWidth*0.067, this->appHeight*0.166);
    this->fourthPatientPhotoWidgetLayout = new QVBoxLayout(fourthPatientPhotoWidget);
    this->fourthPatientInfo = new QLabel();
    this->fourthPatientInfo->setFont(*this->caracterStyle);
    this->fourthPatientInfo->setStyleSheet(this->labelStyleSheet);
    this->fourthPatientInfo->setFixedHeight(this->appHeight*0.028);
    this->fourthPatientInfo->setAlignment(Qt::AlignCenter);

    this->fourthPatientPhoto = new QLabel();
    this->fourthPatientPhoto->setStyleSheet(this->labelStyleSheet);

    this->fourthPatientPhotoWidgetLayout->addWidget(fourthPatientPhoto);
    this->fourthPatientPhotoWidgetLayout->addWidget(fourthPatientInfo);

    this->rightBlackArea = new QWidget();
    this->rightBlackArea->setFixedWidth(this->appWidth*0.34*0.02);
    this->rightBlackArea->setStyleSheet("background-color:transparent");

    this->waittingPatientPhotoesLayout = new QHBoxLayout(waittingPatientPhotoes);
    this->waittingPatientPhotoesLayout->addWidget(leftBlackArea);
    this->waittingPatientPhotoesLayout->addWidget(firstPatientPhotoWidget);
    this->waittingPatientPhotoesLayout->addWidget(secondPatientPhotoWidget);
    this->waittingPatientPhotoesLayout->addWidget(thirdPatientPhotoWidget);
    this->waittingPatientPhotoesLayout->addWidget(fourthPatientPhotoWidget);
    this->waittingPatientPhotoesLayout->addWidget(rightBlackArea);
    this->waittingPatientPhotoesLayout->setSpacing(10);
    this->waittingPatientPhotoesLayout->setMargin(0);

    this->waittingPatientsAndBlackAreaWindowLayout = new QVBoxLayout(waittingPatientsAndBlackAreaWindow);
    this->waittingPatientsAndBlackAreaWindowLayout->addWidget(upBlackArea);
    this->waittingPatientsAndBlackAreaWindowLayout->addWidget(waittingPatientPhotoes);
    this->waittingPatientsAndBlackAreaWindowLayout->addWidget(downBlackArea);
    this->waittingPatientsAndBlackAreaWindowLayout->setSpacing(0);
    this->waittingPatientsAndBlackAreaWindowLayout->setMargin(0);

    //!--------------------------------------------------------------------------------------
    //!the left select button
    //!--------------------------------------------------------------------------------------
    this->leftSelectButton = new QPushButton();
    this->leftSelectButton->setFixedSize(this->appWidth*0.021,this->appHeight*0.093);
    this->leftSelectButton->setIcon(QIcon(":/images/splitter_left.png"));
    this->leftSelectButton->setStyleSheet("background-color:transparent");

    //!--------------------------------------------------------------------------------------
    //!the start and stop button of surgery
    //!--------------------------------------------------------------------------------------
    this->surgeryLaunchButton = new QPushButton("Launch");
    this->surgeryLaunchButton->setFixedSize(this->appWidth*0.857*0.15,this->appHeight*0.857*0.15*0.3);

    this->surgeryTerminateButton = new QPushButton("Terminate");
    this->surgeryTerminateButton->setFixedSize(0,0);

    this->surgeryHandlingWidget = new QWidget();
    this->surgeryHandlingWidgetLayout = new QHBoxLayout(surgeryHandlingWidget);
    this->surgeryHandlingWidgetLayout->addWidget(surgeryLaunchButton);
    this->surgeryHandlingWidgetLayout->addWidget(surgeryTerminateButton);
    this->surgeryHandlingWidgetLayout->setSpacing(0);
    this->surgeryHandlingWidgetLayout->setMargin(0);


    //!--------------------------------------------------------------------------------------
    //!current patient widget
    //!--------------------------------------------------------------------------------------

    this->pictureLeftArea = new QWidget();

    this->currentPatientBreifInformationWidget = new QWidget();
    this->currentPatientBreifInformationWidget->setFixedWidth(this->appWidth*0.857*0.15*0.65);
    this->currentPatientBreifInformationWidgetLayout = new QVBoxLayout(this->currentPatientBreifInformationWidget);
    this->currentPatientInfo = new QLabel();
    this->currentPatientInfo->setFont(*this->caracterStyle);
    this->currentPatientInfo->setStyleSheet(this->labelStyleSheet);
    this->currentPatientInfo->setFixedHeight(this->appHeight*0.028);
    this->currentPatientInfo->setAlignment(Qt::AlignCenter);

    this->currentPatientPhoto = new QLabel();
    this->currentPatientPhoto->setStyleSheet(this->labelStyleSheet);
    this->currentPatientPhoto->setFixedHeight(this->appHeight*0.13);

    this->currentPatientBreifInformationWidgetLayout->addWidget(this->currentPatientPhoto);
    this->currentPatientBreifInformationWidgetLayout->addWidget(this->currentPatientInfo);

    this->waitingPatientsQueue.append(firstPatientPhoto);
    this->waitingPatientsQueue.append(secondPatientPhoto);
    this->waitingPatientsQueue.append(thirdPatientPhoto);
    this->waitingPatientsQueue.append(fourthPatientPhoto);
    this->waitingPatientsQueue.append(currentPatientPhoto);

    this->waitingPatientsNameQueue.append(firstPatientInfo);
    this->waitingPatientsNameQueue.append(secondPatientInfo);
    this->waitingPatientsNameQueue.append(thirdPatientInfo);
    this->waitingPatientsNameQueue.append(fourthPatientInfo);
    this->waitingPatientsNameQueue.append(currentPatientInfo);

    this->pictureRightArea = new QWidget();

    this->pictureInfoArea = new QWidget();
    this->pictureInfoAreaLayout = new QHBoxLayout(pictureInfoArea);
    this->pictureInfoAreaLayout->addWidget(pictureLeftArea);
    this->pictureInfoAreaLayout->addWidget(currentPatientBreifInformationWidget);
    this->pictureInfoAreaLayout->addWidget(pictureRightArea);
    this->pictureInfoAreaLayout->setSpacing(0);
    this->pictureInfoAreaLayout->setMargin(0);

    this->patientHandlingWidget = new QWidget();
    this->patientHandlingWidget->setFixedWidth(this->appWidth*0.857*0.15);
    this->patientHandlingWidgetLayout = new QVBoxLayout(patientHandlingWidget);
    this->patientHandlingWidgetLayout->addWidget(pictureInfoArea);
    this->patientHandlingWidgetLayout->addWidget(surgeryHandlingWidget);
    this->patientHandlingWidgetLayout->setSpacing(0);
    this->patientHandlingWidgetLayout->setMargin(0);

    //!--------------------------------------------------------------------------------------
    //!the right select button
    //!--------------------------------------------------------------------------------------
    this->rightSelectButton = new QPushButton();
    this->rightSelectButton->setFixedSize(this->appWidth*0.021,this->appHeight*0.093);
    this->rightSelectButton->setIcon(QIcon(":/images/splitter_right.png"));
    this->rightSelectButton->setStyleSheet("background-color:transparent");

    //!--------------------------------------------------------------------------------------
    //!patient photo widget: there are 3 photoes of waitting patients and 1 current patient
    //!--------------------------------------------------------------------------------------
    this->patientsPhotoWidget = new QWidget();
    this->patientsPhotoWidgetLayout = new QHBoxLayout(this->patientsPhotoWidget);
    this->patientsPhotoWidgetLayout->addWidget(waittingPatientsAndBlackAreaWindow);
    this->patientsPhotoWidgetLayout->addWidget(leftSelectButton);
    this->patientsPhotoWidgetLayout->addWidget(patientHandlingWidget);
    this->patientsPhotoWidgetLayout->addWidget(rightSelectButton);
    this->patientsPhotoWidgetLayout->setSpacing(0);
    this->patientsPhotoWidgetLayout->setMargin(0);

    //!--------------------------------------------------------------------------------------
    //!the information of the current patient
    //!--------------------------------------------------------------------------------------


    this->nameLabel = new QLabel("Name:");
    this->nameLabel->setFont(*this->caracterStyle);
    this->nameLabel->setStyleSheet(this->labelStyleSheet);

    this->birthdayLabel = new QLabel("Birth:");
    this->birthdayLabel->setFont(*this->caracterStyle);
    this->birthdayLabel->setStyleSheet(this->labelStyleSheet);

    this->sexualLabel = new QLabel("Sex:");
    this->sexualLabel->setFont(*this->caracterStyle);
    this->sexualLabel->setStyleSheet(this->labelStyleSheet);

    this->idNumberLabel = new QLabel("ID:");
    this->idNumberLabel->setFont(*this->caracterStyle);
    this->idNumberLabel->setStyleSheet(this->labelStyleSheet);

    this->nameLineEdit = new QLineEdit();
    this->nameLineEdit->setFont(*this->caracterStyle);
    this->nameLineEdit->setStyleSheet(this->labelStyleSheet);

    this->birthdayLineEdit = new QLineEdit();
    this->birthdayLineEdit->setFont(*this->caracterStyle);
    this->birthdayLineEdit->setStyleSheet(this->labelStyleSheet);

    this->sexualLineEdit = new QLineEdit();
    this->sexualLineEdit->setFont(*this->caracterStyle);
    this->sexualLineEdit->setStyleSheet(this->labelStyleSheet);

    this->idNumberEdit = new QLineEdit();
    this->idNumberEdit->setFont(*this->caracterStyle);
    this->idNumberEdit->setStyleSheet(this->labelStyleSheet);

    patientInfoContainerSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->patientInfoContainer = new QWidget();
    this->patientInfoContainerLayout = new QGridLayout(patientInfoContainer);
    this->patientInfoContainerLayout->addWidget(nameLabel, 0, 0);
    this->patientInfoContainerLayout->addWidget(birthdayLabel, 1, 0);
    this->patientInfoContainerLayout->addWidget(sexualLabel, 2, 0);
    this->patientInfoContainerLayout->addWidget(idNumberLabel, 3, 0);
    this->patientInfoContainerLayout->addWidget(nameLineEdit, 0, 1);
    this->patientInfoContainerLayout->addWidget(birthdayLineEdit, 1, 1);
    this->patientInfoContainerLayout->addWidget(sexualLineEdit, 2, 1);
    this->patientInfoContainerLayout->addWidget(idNumberEdit, 3, 1);
    this->patientInfoContainerLayout->addItem(patientInfoContainerSpacer, 4, 0);

    this->patientInfoContainerLayout->setSpacing(2);
    this->patientInfoContainerLayout->setMargin(0);

    this->leadDoctorLabel = new QLabel("Doctor:");
    this->leadDoctorLabel->setFont(*this->caracterStyle);
    this->leadDoctorLabel->setStyleSheet(this->labelStyleSheet);

    this->therapyTimeLabel = new QLabel("Time:");
    this->therapyTimeLabel->setFont(*this->caracterStyle);
    this->therapyTimeLabel->setStyleSheet(this->labelStyleSheet);

    this->leadDoctorEdit = new QLineEdit();
    this->leadDoctorEdit->setFont(*this->caracterStyle);
    this->leadDoctorEdit->setStyleSheet(this->labelStyleSheet);

    this->therapyTimeEdit = new QLineEdit();
    this->therapyTimeEdit->setFont(*this->caracterStyle);
    this->therapyTimeEdit->setStyleSheet(this->labelStyleSheet);

    this->doctorInfoContainer = new QWidget();
    this->doctorInfoContainerLayout = new QGridLayout(doctorInfoContainer);
    this->doctorInfoContainerLayout->addWidget(leadDoctorLabel, 0, 0);
    this->doctorInfoContainerLayout->addWidget(therapyTimeLabel, 1, 0);
    this->doctorInfoContainerLayout->addWidget(leadDoctorEdit, 0, 1);
    this->doctorInfoContainerLayout->addWidget(therapyTimeEdit, 1, 1);
    this->doctorInfoContainerLayout->setSpacing(2);
    this->doctorInfoContainerLayout->setMargin(0);

    this->commentTextEdit = new QTextEdit();
    this->commentTextEdit->setFont(*this->caracterStyle);
    this->commentTextEdit->setStyleSheet(this->labelStyleSheet);

    this->doctorComment = new QWidget();
    this->doctorCommentLayout = new QVBoxLayout(doctorComment);
    this->doctorCommentLayout->addWidget(doctorInfoContainer);
    this->doctorCommentLayout->addWidget(commentTextEdit);
    this->doctorCommentLayout->setSpacing(2);
    this->doctorCommentLayout->setMargin(0);

    this->personalInformation = new QWidget();
    this->personalInformation->setFixedWidth(this->appWidth*0.857*0.4);

    this->personalInformationLayout = new QHBoxLayout(personalInformation);
    this->personalInformationLayout->addWidget(patientInfoContainer);
    this->personalInformationLayout->addWidget(doctorComment);
    this->personalInformationLayout->setSpacing(2);
    this->personalInformationLayout->setMargin(0);

    //!--------------------------------------------------------------------------------------
    //!the interface of the introduction about patients
    //!--------------------------------------------------------------------------------------
    this->patientsIntroduction = new QWidget();

    this->patientsIntroductionLayout = new QHBoxLayout(this->patientsIntroduction);
    this->patientsIntroductionLayout->addWidget(patientsPhotoWidget);
    this->patientsIntroductionLayout->addWidget(personalInformation);
    this->patientsIntroductionLayout->setSpacing(2);
    this->patientsIntroductionLayout->setMargin(0);

    //!--------------------------------------------------------------------------------------
    //!this area will put something else
    //!--------------------------------------------------------------------------------------
    this->somethingelse = new QWidget();
    this->somethingelse->setFixedHeight(this->appHeight*0.52);

    this->controlBar = new QWidget();
    this->controlBar->setFixedHeight(this->appHeight*0.030);

    this->controlBarLayout = new QHBoxLayout(this->controlBar);

    this->cdRomParseButton =  new QPushButton();
    this->cdRomParseButton->setIcon(QIcon(":/images/Disk.png"));
    this->cdRomParseButton->setIconSize(QSize(this->appWidth*0.015,this->appWidth*0.015));
    this->cdRomParseButton->setStyleSheet("background-color:transparent");
    this->cdRomParseButton->setFixedSize(this->appWidth*0.020, this->appWidth*0.020);

    this->addPatientButton =  new QPushButton();
    this->addPatientButton->setIcon(QIcon(":/images/icon.png"));
    this->addPatientButton->setIconSize(QSize(this->appWidth*0.015,this->appWidth*0.015));
    this->addPatientButton->setStyleSheet("background-color:transparent");
    this->addPatientButton->setFixedSize(this->appWidth*0.020, this->appWidth*0.020);

    controlBarSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->controlBarLayout->addWidget(this->cdRomParseButton);
    this->controlBarLayout->addWidget(this->addPatientButton);
    this->controlBarLayout->addSpacerItem(this->controlBarSpacer);

    this->controlBarLayout->setSpacing(0);
    this->controlBarLayout->setMargin(0);

    //!--------------------------------------------------------------------------------------
    //!the total information of patient and doctors
    //!--------------------------------------------------------------------------------------
    this->totalInformation = new QWidget();
    this->totalInformationLayout = new QVBoxLayout(this->totalInformation);
    this->totalInformationLayout->addWidget(this->patientsIntroduction);
    this->totalInformationLayout->addWidget(this->somethingelse);
    this->totalInformationLayout->setSpacing(0);
    this->totalInformationLayout->setMargin(0);

    //!--------------------------------------------------------------------------------------
    //!the layout of patients widget
    //!--------------------------------------------------------------------------------------
    this->patientsWidgetLayout = new QVBoxLayout(this);
    this->patientsWidgetLayout->addWidget(this->controlBar);
    this->patientsWidgetLayout->addWidget(this->totalInformation);
    this->patientsWidgetLayout->setSpacing(0);
    this->patientsWidgetLayout->setMargin(0);
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief PatientsWidget::addPatientToListWidget
//! \param patients
//!
void PatientsWidget::addPatientToWidget(QString path){

    QListWidgetItem *patientItem = new QListWidgetItem();
    qDebug()<<path;
    patientItem->setIcon(QIcon(path));

}

 void PatientsWidget::keyPressEvent(QKeyEvent *event){
     switch(event->key()){
        case Qt::Key_Left:
            this->doLeftSelect();
            break;
        case Qt::Key_Right:
            this->doRightSelect();
            break;
     }
 }
