#ifndef SURGERYPLANWINDOW_H
#define SURGERYPLANWINDOW_H

#include <QWidget>
#include <QWidget>
#include <QFrame>
#include <QSplitter>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QFileInfo>
#include <QDir>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QLCDNumber>
#include <QTime>
#include <QDateTime>

//！VTK - auto initialization
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)
VTK_MODULE_INIT(vtkRenderingFreeTypeOpenGL)
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL)

#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkImageViewer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkJPEGReader.h>
#include <vtkMetaImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkVolumeRayCastCompositeFunction.h>
#include <vtkVolumeRayCastMapper.h>
#include <vtkPiecewiseFunction.h>
#include <vtkColorTransferFunction.h>
#include <vtkVolumeProperty.h>
#include <vtkDataSet.h>
#include <vtkPointData.h>
#include <vtkDataArray.h>
#include <QVTKWidget.h>
#include <vtkImageData.h>

#include <vtkOBJReader.h>
#include <vtkOrientationMarkerWidget.h>

#include <Patient.h>
#include <CPushButton.h>
#include <PlottingBoard.h>
#include <PatientWidgetConfigurationBoard.h>
#include <ColorChooseWindow.h>
#include <vtkEventQtSlotConnect.h>
#include <SystemDispatcher.h>

#include "CurveReformationWindow.h"
#include "AlgorithmTestPlatform.h"

struct TransferOptionStates{
    bool opacityTransferOptionChoosen = false;
    bool colorTransferOptionChoosen = false;
    bool gradientTransferOptionChoosen = false;
};

struct TransferCurveIndex{
    int opacityTransferCurveIndex;
    int colorTransferCurveIndex;
    int gradientTransferCurveIndex;
};

struct ImageOptionStates{
    bool originalOptionState;
    bool transparentBrainOptionState;
    bool greyMatterOptionState;
    bool whiteMatterOptionState;
    bool vesselOptionState;
    bool interventionalRouteOptionState;
};

class SurgeryPlanWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SurgeryPlanWindow(QRect rect,
                               QTime* surgeryTime,
                               SystemDispatcher* systemDispatcher,
                               AlgorithmTestPlatform *algorithmTestPlatform);
    void displayWindow();

    void createRandomVtkImageData();
    void display(vtkImageData *imgToBeDisplayed);
    void displaySize();
    void setPatientHandling(Patient *patientHandling);
    void update();
    void setStartTime(int start_time);

protected:
    vtkEventQtSlotConnect* MraConnections;

private:
    int start_time;
    int current_time;
    QTime* surgeryTime;

    QTimer *timer;

    AlgorithmTestPlatform *algorithmTestPlatform;

    double transformationPlottingBoard_AbscissaValue;
    double transformationPlottingBoard_OrdinateValue;
    bool transformationPlottingBoard_Clicked;
    int lockingTransformationPointIndex;

    ColorChooseWindow* colorChooseWindow;

    PatientWidgetConfigurationBoard *patientWidgetConfigurationBoard;

    //MedicalImageHandler *medicalImageHandler;
    QString mraImagefilePath;

    QPixmap *pixmap;

    QFrame *controlBar;
    QHBoxLayout *controlBarLayout;

    CPushButton *imageConfigurationButton;
    CPushButton *imageUpdateButton;
    CPushButton *curveReformationButton;

    CurveReformationWindow* curveReformationWindow;

    CPushButton *beginTherapyButton;
    QSpacerItem *spacer_controlbar;

    QSplitter *mainSplitter;

    //! patient's information widget
    QFrame *patientInformationWidget;
    QVBoxLayout *patientInformationLayout;

    QFrame *patientTitleBar;
    QHBoxLayout *patientTitleBarLayout;
    QWidget *briefWidget;
    QLabel *patientTitleLabel;
    QLabel *photoWidget;
    QSpacerItem *spacer_1;
    QSpacerItem *spacer_2;

    QFrame *patientPersonelInformationBar;
    QHBoxLayout * patientPersonelInformationBarLayout;
    QLabel *nameLabel;
    QLabel *birthLabel;
    QLabel *sexualLabel;
    QLabel *medicalDateLabel;
    QLineEdit *nameLineEdit;
    QLineEdit *birthLineEdit;
    QLineEdit *sexualLineEdit;
    QLineEdit *medicalDateLineEdit;

    QFrame *patientClinicalWidgetsContainer;
    QHBoxLayout *patientClinicalWidgetsContainerLayout;
    QWidget *patientMRAImageOptionWidget;
    QVBoxLayout *patientMRAImageOptionWidgetLayout;

    QWidget *patientImageInformationWidget;
    QHBoxLayout* patientImageInformationWidgetLayout;
    QLabel* surgeryPlanWindowLabel;
    QLCDNumber *elapsedTimeLabel;
    //QPushButton* sugeryEndnessButton;

    QGroupBox * histogramGroupBox;
    QVBoxLayout *histogramGroupBoxLayout;
    QWidget *imageStatisticsWidget;
    QGridLayout *imageStatisticsWidgetLayout;

    QLabel *grayscaleValueNumberLabel;
    QLabel *grayscaleValueMeanLabel;
    QLabel *grayscaleValueMedianLabel;
    QLabel *grayscaleValueStandardDeviationLabel;
    QLabel *grayscaleValueMaximumValueLabel;
    QLabel *grayscaleValueMinimumValueLabel;

    QLineEdit *grayscaleValueNumberLineEdit;
    QLineEdit *grayscaleValueMeanLineEdit;
    QLineEdit *grayscaleValueMedianLineEdit;
    QLineEdit *grayscaleValueStandardDeviationLineEdit;
    QLineEdit *grayscaleValueMaximumValueLineEdit;
    QLineEdit *grayscaleValueMinimumValueLineEdit;

    PlottingBoard *histogramPlottingBoard;

    QGroupBox * volumeRenderingGroupBox;
    QVBoxLayout *volumeRenderingGroupBoxLayout;
    QWidget *transferChoicesWidget;
    QHBoxLayout *transferChoicesLayout;
    QLabel *transferChoiceLabel;
    QRadioButton *opacityTransferChoice;
    QRadioButton *colorTransferChoice;
    QRadioButton *gradientTransferChoice;
    QSpacerItem *transferChoicesWidgetSpacer;

    PlottingBoard *transformationPlottingBoard;

    QWidget *transformationIndicationBar;
    QHBoxLayout *transformationIndicationBarLayout;
    QLabel *currentGrayScaleValueLabel;
    QLabel *currentTransformationValueLabel;
    CPushButton *transformationButton;
    QLineEdit *currentGrayScaleValueLineEdit;
    QLineEdit *currentTransformationValueLineEdit;


    QSpacerItem *patientMRAImageOptionWidgetSpacer;

    QWidget *patientMRAImageConfigurationWidget;
    QVBoxLayout *patientMRAImageConfigurationWidgetLayout;
    QWidget *patientMRAImageOption;
    QHBoxLayout *patientMRAImageOptionLayout;

    CPushButton *originalOption;
    CPushButton *transparentBrainOption;
    CPushButton *greyMatterOption;
    CPushButton *whiteMatterOption;
    CPushButton *vesselOption;
    CPushButton *interventionalRouteOption;
    QPushButton *quitSurgeryPlanButton;

    ImageOptionStates imageOptionStates;

    QLabel *patientMRAImageOptionLabel;

    QWidget *patientMRAImageWidget;
    QHBoxLayout *patientMRAImageWidgetLayout;


    QVTKWidget *patientMRAImage;

    QWidget *patientMRAImageManipulation;


    vtkVolumeRayCastMapper *volumeMapper;
    vtkVolumeRayCastCompositeFunction  *compositeFunction;
    vtkVolume *volume;
    vtkSmartPointer<vtkRenderWindow> renderWindow;
    vtkSmartPointer<vtkRenderer> renderer;

    vtkPiecewiseFunction*opacityTransferFunction;
    vtkPiecewiseFunction *gradientTransferFunction;
    vtkColorTransferFunction *colorTransferFunction;
    vtkVolumeProperty*volumeProperty;

    //vtkRenderWindowInteractor * iren;
    vtkInteractorStyleTrackballCamera *style;
    vtkBoxWidget *boxWidget;
    vtkMyCallback *callBack;

    TransferOptionStates transferOptionStates;
    TransferCurveIndex transferCurveIndex;

    // doctor's information widget
    QFrame *doctorInformationWidget;
    QGridLayout *mainLayout;
    Patient *patientHandling;

    vtkImageData *enhancedImage = NULL;

    int x;
    int y;
    int appWidth;
    int appHeight;
     SystemDispatcher* systemDispatcher;

    void constructPatientInformationWidget();
    void constructDoctorInformationWidget();
    void constructControlBar();
    void initialisation();
    void regroupAllComponents();
    void setConnections();
    void drawBackground();
    void initVariable();

    void updatePatientPersonelInformation();
    void updatePatientPersonelPhoto();
    void displayPatientMRAImage();
    void updatePatientMRAImageStatistics();
    void updatePatientMRAImageHistogram();
    void updatePatientMRAImageTransformationCurves();
    void removeCurveBy(int index);
    void updatePatientMRAImage();
    void generateNewOpacityPoint(double abscissa, double ordinate);
    void generateNewColorPoints(double abscissa, double ordinate);
    void generateNewGradientPoint(double abscissa, double ordinate);
    void generateInitColorPoints(double abscissa, int colorCount);
    void initialRendering();
    void opacityPointTracking();
    void colorPointTracking();
    void gradientPointTracking();
    //void calculateCenterOfTheVolume();

signals:
    void finished();
    void error(QString err);

public slots:
    void mainSplitterMoved(int i , int j);
    void process();
    void opacityTransformationStateChanged(bool state);
    void colorTransformationStateChanged(bool state);
    void gradientTransformationStateChanged(bool state);
    void generateNewTransformationPoint(QMouseEvent* event);
    void transformPointTracking(QMouseEvent* event);
    void lockTargetPoint(QMouseEvent* event);
    void positioningTransformPoint(QMouseEvent* event);
    void updateCoords(vtkObject* obj);

    void originalOptionHovered();
    void originalOptionClicked();
    void originalOptionReleased();
    void originalOptionLeaved();

    void transparentBrainOptionHovered();
    void transparentBrainOptionClicked();
    void transparentBrainOptionReleased();
    void transparentBrainOptionLeaved();

    void greyMatterOptionHovered();
    void greyMatterOptionClicked();
    void greyMatterOptionReleased();
    void greyMatterOptionLeaved();

    void whiteMatterOptionHovered();
    void whiteMatterOptionClicked();
    void whiteMatterOptionReleased();
    void whiteMatterOptionLeaved();

    void vesselOptionHovered();
    void vesselOptionClicked();
    void vesselOptionReleased();
    void vesselOptionLeaved();

    void interventionalRouteOptionHovered();
    void interventionalRouteOptionClicked();
    void interventionalRouteOptionReleased();
    void interventionalRouteOptionLeaved();

    void displayConfigurationBoard();
    void getVesselEnhancedImage();
    void stopSurgery();

    void displayCurveReformatwionWindow();
    void closeSurgeryPlanWindow();

    void showTime();

signals:

public slots:


};

#endif // SURGERYPLANWINDOW_H
