#ifndef CURVEREFORMATIONWINDOW_H
#define CURVEREFORMATIONWINDOW_H


#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVTKWidget.h>

#include <QWidget>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include "vtkRenderWindowInteractor.h"
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include "vtkFixedPointVolumeRayCastMapper.h"
#include "vtkColorTransferFunction.h"
#include "vtkPiecewiseFunction.h"
#include "vtkVolumeProperty.h"
#include "vtkVolume.h"
#include "vtkImageMapToColors.h"
#include "vtkPolyDataMapper.h"
#include "vtkCutter.h"
#include "vtkPlane.h"
#include "vtkImageActor.h"
#include "vtkImageData.h"
#include "vtkImageCast.h"
#include "vtkPointData.h"
#include "vtkImageShiftScale.h"
#include "vtkPolyDataToImageStencil.h"
#include "vtkImageStencil.h"
#include "vtkLookupTable.h"
#include "vtkImagePlaneWidget.h"
#include "vtkCellArray.h"
#include "vtkPlaneWidget.h"
#include "vtkProperty.h"
#include "vtkCommand.h"
#include "vtkProbeFilter.h"
#include "vtkImplicitPlaneWidget.h"
#include "vtkClipPolyData.h"
#include "vtkSphereSource.h"


#include <QFile>
#include <QDebug>
#include "vtkPoints.h"
#include <vector>
#include <QByteArray>

#include <vtkPolyVertex.h>
#include <vtkUnstructuredGrid.h>
#include <vtkDataSetMapper.h>

#include <vtkProperty.h>
#include <vtkWidgetCallbackMapper.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkSimplePointsReader.h>
#include <vtkPolyDataMapper.h>
#include <vtkMetaImageReader.h>
#include <vtkImageViewer2.h>

#include <vtkBoxWidget.h>
#include <vtkTransform.h>


class vtkWidgetCall : public vtkCommand
{
public:
 static vtkWidgetCall *New()
 {
  return new vtkWidgetCall;
 }
public:
 virtual void Execute(vtkObject *caller, unsigned long eventId, void *callData){
    vtkPlaneWidget *pWidget = vtkPlaneWidget::SafeDownCast(caller);
    pWidget->GetPlane(pPlane);
 }
public:
 vtkPlane *pPlane ;
};

class vtkMyCallback : public vtkCommand
{
public:
  static vtkMyCallback *New()
    { return new vtkMyCallback; }
  virtual void Execute(vtkObject *caller, unsigned long, void*)
    {
      vtkSmartPointer<vtkTransform> t =
    vtkSmartPointer<vtkTransform>::New();
      vtkBoxWidget *widget = reinterpret_cast<vtkBoxWidget*>(caller);
      widget->GetTransform(t);
      widget->GetProp3D()->SetUserTransform(t);
    }
};


class CurveReformationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit CurveReformationWindow(QWidget *parent = 0);
    ~CurveReformationWindow();
    void constructIHM();
    void setConnections();

    void sourceImgDisplay();
    void vesselDisplay();
    void slicerDisplay();
    void outComingcprDisplay();
signals:

public slots:
    void brea();

private:
    QGroupBox *sourceImgBox;
    QGroupBox *vesselBox;
    QGroupBox *slicerImgBox;
    QGroupBox *outComingcprImgBox;

    QWidget *topWidget;
    QWidget *middleWidget;
    QWidget *controlBarWidget;

    QVBoxLayout *mainLayout;
    QHBoxLayout *topLayout;
    QHBoxLayout *middleLayout;
    QHBoxLayout *controlBarLayout;

    QPushButton *OkBtn;
    QPushButton *ResetBtn;

    QSpacerItem *controlBarSpace;

    QVTKWidget *m_Fwidget;
    QVTKWidget *m_Swidget;
    QVTKWidget *m_Twidget;
    QVTKWidget *m_Fowidget;

    QHBoxLayout *m_FLayout;
    QHBoxLayout *m_SLayout;
    QHBoxLayout *m_TLayout;
    QHBoxLayout *m_FoLayout;

    vtkRenderer *pRender1;
    vtkRenderer *pRender2;
    vtkRenderWindow *pWin;
    vtkRenderWindow *pWin2;
    vtkRenderWindowInteractor *pInt;
    vtkMetaImageReader *pReader;
    vtkImageShiftScale *m_pShift;
    vtkFixedPointVolumeRayCastMapper *pMapper;
    vtkColorTransferFunction *pColor;
    vtkPiecewiseFunction *pPiceFun;
    vtkImageViewer2 *viewer;
    vtkVolumeProperty *pProperty;
    vtkVolume* pVolume;
    vtkPlaneWidget *pWidget;
   // vtkPlane *pPlane;
    vtkCutter *pCut;
    vtkPolyDataMapper *selectMapper;
    vtkActor *pActor;
    vtkWidgetCall *pCall;
    vtkBoxWidget* boxWidget;
    vtkMyCallback* callback;

};
#endif // CURVEREFORMATIONWINDOW_H
