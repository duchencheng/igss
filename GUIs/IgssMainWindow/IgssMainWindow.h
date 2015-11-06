#ifndef  WIDGET_H
#define WIDGET_H

#define vtkRenderingCore_AUTOINIT 4(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingFreeTypeOpenGL,vtkRenderingOpenGL)
#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)

#include <QWidget>
#include <QPushButton>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QVTKWidget.h>
#include <QLineEdit>
#include <QTextEdit>
#include <QDesktopWidget>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include <QApplication>
#include <QPoint>
#include <QTime>

#include <QRect>

#include <MRAFileReader.h>
#include <IgssImage.h>
#include <IgssVtkImageConverter.h>
#include <SystemDispatcher.h>
#include <PatientsWidget.h>
#include <ReplaysWidget.h>
#include <SurgerySystemWidget.h>
#include <SurgeryPlanWindow.h>
#include <GuidewareTrackingWindow.h>
#include <AlgorithmTestPlatform.h>

//#include <vtkSmartPointer.h>
//#include <vtkImageData.h>
//#include <vtkVolume.h>
//#include <vtkVolumeRayCastCompositeFunction.h>
//#include <vtkVolumeRayCastMapper.h>
//#include <vtkRenderWindow.h>
//#include <vtkRenderer.h>


typedef struct{
    int screenIndex;
    QRect rect;
}Screen;

class IgssMainWindow : public QWidget{
    Q_OBJECT

public:
    IgssMainWindow(SystemDispatcher *systemDispatcher);
#ifdef win32
    ~Widget();
#endif
    void findPatientExisted();
    void initVariable();
    void initVisualizationComponents();
    void constructIHM();
    void setConnections();
    void display();
    void displayMraImage(vtkImageData* input);
    void setSystemDispatecher(SystemDispatcher* systemDispatcher);
    void readImageFileFrom(QString path);
    void readImageFromVtkConvert();
    void setSystemStatus(QString status);
    void drawBackground();

private:
    QTime* surgeryTimer;

    QDesktopWidget *desktop;
    Screen *screen;

    QFont *englishCaracterStyle;

    QPixmap *pixmap;

    QVBoxLayout* igssMainWindowLayout;
    QVBoxLayout *controlBoardLayout;
    QHBoxLayout *mainPlatformLayout;
    QGridLayout *statusBarLayout;
    QHBoxLayout *systemInformationBoardWidgetLayout;
    QVBoxLayout *controlAreaLayout;

    QWidget *mainPlatform;
    QWidget *configurationBoard;
    QWidget *controlBoard;
    QWidget *statusBar;
    QWidget *controlArea;
    QWidget *systemInformationBoardWidget;

    QSpacerItem* controlAreaItem;

    AlgorithmTestPlatform* algorithmTestPlatform;

    QPushButton *displayStatusButton;
    QPushButton *closeButton;
    QPushButton *pickInformationBoardButton;

    QTabWidget *systemInformationBoard;

    QVTKWidget* mraImageDisplayWindow;

    QString systemInformationBoardStyleSheet;

    PatientsWidget* patientsWidget;
    ReplaysWidget*replaysWidget;
    SurgerySystemWidget* surgerySystemWidget;

    //! component for mra image display
    vtkVolumeRayCastMapper* volumeMapper;
    vtkVolumeRayCastCompositeFunction *compositeFunction;
    vtkVolume *volume;
    vtkSmartPointer<vtkRenderWindow> renderWindow;
    vtkSmartPointer<vtkRenderer> renderer;


    SystemDispatcher* systemDispatcher;
    QString mhdImagePath;
    IgssImage* mraImage;
    IgssImage* igssImage;
    MRAFileReader* mhdFileReader;
    vtkSmartPointer<vtkImageData>vtkImage;
    IgssVtkImageConverter* igssVtkImageConverter;

    SurgeryPlanWindow* surgeryPlanWindow;
    PatientInformationWidget* patientInformationWidget;
    GuidewareTrackingWindow* guidewareTrackingWindow;

    int flag;
    int primary_screen_width;
    int primary_screen_height;
    //int patientsWidget_width;
    //int patientsWidge_height;
    int screen_count;
    int primary_screen;

    QPoint mousePosition;
    QPoint mouseMovingPosition;
    bool mouseLeftButtonPressed;
    bool pickInformationBoardButtonIsClicked;

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void closeSystem();
    void pickInformationBoardButtonClicked();
};

#endif // WIDGET_H
