#ifndef PATIENTSWIDGET_H
#define PATIENTSWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <SystemDispatcher.h>
#include <Patients.h>
#include <QDebug>
#include <QTextEdit>
#include <AlgorithmTestPlatform.h>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTime>
#include "DicomCDRomReader.h"
#include "SurgeryPlanWindow.h"
#include "GuidewareTrackingWindow.h"
#include "PatientInformationWidget.h"
#include "SurgeryLoadingWindow.h"

class PatientsWidget : public QWidget
{
    Q_OBJECT
public:
    PatientsWidget(SystemDispatcher* dispatcher,
                   AlgorithmTestPlatform *algorithmTestPlatform,
                   SurgeryPlanWindow* surgeryPlanWindow,
                   PatientInformationWidget* patientInformationWidget,
                   GuidewareTrackingWindow* guidewareTrackingWindow,
                   QTime* surgeryTimer,
                   QFont *caracterStyle,
                   int appWidth,
                   int appHeight);

    void initVariable();
    void constructIHM();
    void findPatientExisted();
    void setConnections();
    void addPatientToWidget(QString path);
    void displayLastFiveOrLess();
    void keyPressEvent(QKeyEvent *event);
    void displayCurrentPatinetInfo();

    int testX();
    int testY();

private:
    SystemDispatcher* dispatcher;

    QVBoxLayout* patientsWidgetLayout;
    QVBoxLayout* totalInformationLayout;
    QHBoxLayout* patientsIntroductionLayout;
    QHBoxLayout* patientsPhotoWidgetLayout;
    QVBoxLayout* waittingPatientsAndBlackAreaWindowLayout;
    QHBoxLayout* waittingPatientPhotoesLayout;
    QVBoxLayout* patientHandlingWidgetLayout;
    QHBoxLayout* pictureInfoAreaLayout;
    QHBoxLayout* controlBarLayout;
    QHBoxLayout* personalInformationLayout;
    QGridLayout*  patientInfoContainerLayout;
    QGridLayout*  doctorInfoContainerLayout;
    QVBoxLayout* doctorCommentLayout;
    QVBoxLayout* currentPatientBreifInformationWidgetLayout;
    QVBoxLayout* firstPatientPhotoWidgetLayout;
    QVBoxLayout* secondPatientPhotoWidgetLayout;
    QVBoxLayout* thirdPatientPhotoWidgetLayout;
    QVBoxLayout* fourthPatientPhotoWidgetLayout;
    QHBoxLayout* surgeryHandlingWidgetLayout;

    QWidget* controlBar;
    QWidget* patientsIntroduction;
    QWidget* personalInformation;
    QWidget* patientsPhotoWidget;
    QWidget* somethingelse;
    QWidget* totalInformation;
    QWidget* patientHandlingWidget;
    QWidget* pictureInfoArea;
    QWidget* currentPatientBreifInformationWidget;
    QWidget* pictureLeftArea;
    QWidget* pictureRightArea;
    QWidget* surgeryHandlingWidget;
    QWidget* upBlackArea;
    QWidget* waittingPatientPhotoes;
    QWidget* downBlackArea;
    QWidget* leftBlackArea;
    QWidget* rightBlackArea;
    QWidget* patientInfoContainer;
    QWidget* doctorComment;
    QWidget* doctorInfoContainer;
    QWidget* firstPatientPhotoWidget;
    QWidget* secondPatientPhotoWidget;
    QWidget* thirdPatientPhotoWidget;
    QWidget* fourthPatientPhotoWidget;

    QLabel* firstPatientPhoto;
    QLabel* secondPatientPhoto;
    QLabel* thirdPatientPhoto;
    QLabel* fourthPatientPhoto;
    QLabel* fifthPatientPhoto;

    QLabel* firstPatientInfo;
    QLabel* secondPatientInfo;
    QLabel* thirdPatientInfo;
    QLabel* fourthPatientInfo;

    QLabel*currentPatientPhoto;
    QLabel*currentPatientInfo;


    QTextEdit* commentTextEdit;

    QLabel* nameLabel;
    QLabel* birthdayLabel;
    QLabel* sexualLabel;
    QLabel* idNumberLabel;
    QLabel* leadDoctorLabel;
    QLabel* therapyTimeLabel;

    QLineEdit* nameLineEdit;
    QLineEdit* birthdayLineEdit;
    QLineEdit* sexualLineEdit;
    QLineEdit* idNumberEdit;
    QLineEdit* leadDoctorEdit;
    QLineEdit* therapyTimeEdit;

    QFont *caracterStyle;

    QWidget* waittingPatientsAndBlackAreaWindow;

    QPushButton* leftSelectButton;
    QPushButton* rightSelectButton;
    QPushButton* cdRomParseButton;
    QPushButton* addPatientButton;
    QPushButton* surgeryLaunchButton;
    QPushButton* surgeryTerminateButton;


    AlgorithmTestPlatform *algorithmTestPlatform;

    SurgeryPlanWindow* surgeryPlanWindow;
    GuidewareTrackingWindow* guidewareTrackingWindow;
    PatientInformationWidget* patientInformationWidget;
    SurgeryLoadingWindow* surgeryLoadingWindow;

    QSpacerItem* controlBarSpacer;
    QSpacerItem* patientInfoContainerSpacer;

    DicomCDRomReader *dicomCDRomReader;

    QList<QLabel*> waitingPatientsQueue;
    QList<QLabel*> waitingPatientsNameQueue;
    QStringList currentPatinetInfoQueue;
    QStringList waitingPatientsPhotoStringQueue;
    QStringList waitingPatientsStringNameQueue;
    QStringList waitingPatientsIDQueue;

    int appWidth;
    int appHeight;
    int numberOfPatient;
    bool surgeryLaunched;
    bool surgeryTerminated;

    QString labelStyleSheet;
    QTime* surgeryTimer;

signals:
public slots:
    void doParseCdRom();
    void launchSurgery();
    void terminateSurgery();
    void addPatient();
    void doLeftSelect();
    void doRightSelect();

};

#endif // PATIENTSWIDGET_H
