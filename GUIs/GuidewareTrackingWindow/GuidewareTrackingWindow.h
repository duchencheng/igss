#ifndef GUIDEWARETRACKINGWINDOW_H
#define GUIDEWARETRACKINGWINDOW_H

#include <Patient.h>
#include <SystemDispatcher.h>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include <QVTKWidget.h>
#include "CurveReformationWindow.h"

class GuidewareTrackingWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GuidewareTrackingWindow(QRect rect,
                                     SystemDispatcher* systemDispatcher);
    ~GuidewareTrackingWindow();
    void initVariable();
    void displayWindow();
    void constructionIHM();
    void setConnections();
    void drawBackground();
    void testVtkwidget();


private:
    int x;
    int y;
    int width;
    int height;
    Patient* patientHandling;
    SystemDispatcher* systemDispatcher;

    QFont *caracterStyle;
    QString windowStyleSheet;

    QPixmap *pixmap;

    QGridLayout* guidewareTrackingLayout;
    QHBoxLayout* vtkDisplayBoardLayout;
    QVBoxLayout* guideControlBoardLayout;
    QVBoxLayout* surgeryInformationLayout;
    QGridLayout* controlButtonAreaLayout;

    QPushButton* untitledButton1;
    QPushButton* untitledButton2;
    QPushButton* untitledButton3;
    QPushButton* untitledButton4;

    QWidget* nameBar;
    QWidget* vtkDisplayBar;
    QWidget* guideControlBoard;
    QWidget* vtkDisplayBoard;
    QWidget* primaryDisplay;
    QWidget* guidewareTrackingDisplay;
    QWidget* surgeryInformation;
    QWidget* controlButtonArea;
    QWidget* unknownArea;

    QVTKWidget* f_vtkwidget;
    QHBoxLayout* l_layout;

    QLabel* surgeryID;
    QLabel* patientName;
    QLabel* surgeryDate;

private slots:
    void closeSystem();
    void VTKDisplay();
};

#endif // GUIDEWARETRACKINGWINDOW_H
