#include "CurveReformationWindow.h"

CurveReformationWindow::CurveReformationWindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(800,600);
    this->setWindowTitle("Curved Planar Reformation");
    this->constructIHM();
    this->setConnections();
    //this->sourceImgDisplay();
    this->vesselDisplay();
    //this->slicerDisplay();
    this->outComingcprDisplay();
}

CurveReformationWindow::~CurveReformationWindow()
{

}

//!------------------------------------------------------------------------
//!
//! \brief CurveReformationWindow::constructIHM
//!
void CurveReformationWindow::constructIHM(){

    topWidget = new QWidget();
    topWidget->setFixedHeight(275);
    topLayout = new QHBoxLayout(topWidget);
    sourceImgBox = new QGroupBox();
    m_Fwidget = new QVTKWidget();
    m_FLayout = new QHBoxLayout(sourceImgBox);
    m_FLayout->addWidget(m_Fwidget);
    sourceImgBox->setFixedSize(400,240);
    sourceImgBox->setTitle("sourceImgData window");
    sourceImgBox->setAlignment(Qt::AlignCenter);
    sourceImgBox->setStyleSheet("QGroupBox{background-color:SkyBlue;}");
    sourceImgBox->setFont(QFont("Segoe UI", 12, QFont::AnyStyle, true));
    slicerImgBox =new QGroupBox();
    m_Swidget = new QVTKWidget();
    m_Swidget->setStyleSheet("color:red");
    m_SLayout = new QHBoxLayout(slicerImgBox);
    m_SLayout->addWidget(m_Swidget);
    slicerImgBox->setFixedSize(400,240);
    slicerImgBox->setTitle("slicerImgData window");
    slicerImgBox->setAlignment(Qt::AlignCenter);
    slicerImgBox->setFont(QFont("Segoe UI", 12, QFont::AnyStyle, true));
    slicerImgBox->setStyleSheet("QGroupBox{background-color:SkyBlue;}");
    topLayout->addWidget(sourceImgBox);
    topLayout->addWidget(slicerImgBox);
    topLayout->setSpacing(0);
    topLayout->setMargin(1);

    //!-------------------------------------------------------------------------

    middleWidget = new QWidget();
    middleWidget->setFixedHeight(275);
    middleLayout = new QHBoxLayout(middleWidget);
    vesselBox = new QGroupBox();
    m_Twidget = new QVTKWidget();
    m_Twidget->setStyleSheet("color:red");
    m_TLayout = new QHBoxLayout(vesselBox);
    m_TLayout->addWidget(m_Twidget);
    vesselBox->setFixedSize(400,240);
    vesselBox->setTitle("vesselImgData window");
    vesselBox->setAlignment(Qt::AlignCenter);
    vesselBox->setStyleSheet("color:red");
    vesselBox->setFont(QFont("Segoe UI", 12, QFont::AnyStyle, true));
    vesselBox->setStyleSheet("QGroupBox{background-color:SkyBlue;}");
    outComingcprImgBox =new QGroupBox();
    m_Fowidget = new QVTKWidget();
    m_FoLayout = new QHBoxLayout(outComingcprImgBox);
    m_FoLayout->addWidget(m_Fowidget);
    outComingcprImgBox->setFixedSize(400,240);
    outComingcprImgBox->setTitle("outComingCprImgData window");
    outComingcprImgBox->setAlignment(Qt::AlignCenter);
    outComingcprImgBox->setStyleSheet("color:blue");
    outComingcprImgBox->setFont(QFont("Segoe UI", 12, QFont::AnyStyle, true));
    outComingcprImgBox->setStyleSheet("QGroupBox{background-color:SkyBlue;}");
    middleLayout->addWidget(vesselBox);
    middleLayout->addWidget(outComingcprImgBox);
    middleLayout->setSpacing(0);
    middleLayout->setMargin(1);

    //!--------------------------------------------------------------------------
    controlBarWidget = new QWidget();
    controlBarLayout = new QHBoxLayout(controlBarWidget);
    OkBtn = new QPushButton("OK");
    ResetBtn = new QPushButton("EXIT");
    controlBarSpace = new QSpacerItem(1,10, QSizePolicy::Expanding, QSizePolicy::Expanding);
    controlBarLayout->addItem(controlBarSpace);
    controlBarLayout->addWidget(OkBtn);
    controlBarLayout->addWidget(ResetBtn);
    controlBarLayout->setSpacing(0);


    //!------------------------------------------------------

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(topWidget);
    mainLayout->addWidget(middleWidget);
    mainLayout->addWidget(controlBarWidget);
}

//!------------------------------------------------------------------------
//!
//! \brief CurveReformationWindow::setConnections
//!
void CurveReformationWindow::setConnections(){
    this->connect(ResetBtn,SIGNAL(clicked()),this,SLOT(brea()));
    //this->connect(OkBtn,SIGNAL(clicked(),this,SLOT()));
}

//!------------------------------------------------------------------------
//!
//! \brief CurveReformationWindow::brea
//!
void CurveReformationWindow::brea(){
    this->close();
}

//!------------------------------------------------------------------------
//!
//! \brief CurveReformationWindow::sourceImgDisplay
//!
void CurveReformationWindow::sourceImgDisplay(){
    pRender1 = vtkRenderer::New();
    pWin = vtkRenderWindow::New();
    pInt = vtkRenderWindowInteractor::New();
    //pWin->SetSize(400,250);
    pWin->AddRenderer(pRender1);
    pInt->SetRenderWindow(pWin);

    pReader =  vtkMetaImageReader::New();
    pReader->SetFileName("E:\\dataset05\\image05.mhd");
    pReader->Update();

    double range[2];
    pReader->GetOutput()->GetScalarRange(range);
    m_pShift = vtkImageShiftScale::New();
    m_pShift->SetShift(-1.0*range[0]);
    m_pShift->SetScale(255.0/(range[1]-range[0]));
    m_pShift->SetOutputScalarTypeToChar();
    m_pShift->SetInputConnection(pReader->GetOutputPort());
    m_pShift->ReleaseDataFlagOff();
    m_pShift->Update();
    pMapper = vtkFixedPointVolumeRayCastMapper::New();
    pMapper->SetInputConnection(pReader->GetOutputPort());//Fisrt:project
    pColor = vtkColorTransferFunction::New();//Second:color
    pColor->AddRGBSegment(0,1,1,1,255,1,1,1);
    pPiceFun = vtkPiecewiseFunction::New();//Third: vtkPiecwise
    pPiceFun->AddSegment(0,0,3000,1);

    pMapper->SetBlendModeToMaximumIntensity();
    viewer = vtkImageViewer2::New();
    viewer->SetInputConnection(pReader->GetOutputPort());
    pProperty = vtkVolumeProperty::New();
    pProperty->SetColor(pColor);
    pProperty->SetScalarOpacity(pPiceFun);
    pProperty->ShadeOff();
    pVolume = vtkVolume::New();
    pVolume->SetProperty(pProperty);
    pVolume->SetMapper(pMapper);//get volume object
    pRender1->AddVolume(pVolume);//add volume to renderer
    pWidget = vtkPlaneWidget::New();
    pWidget->SetInteractor(pInt);
    pWidget->SetInputConnection(pReader->GetOutputPort());
    pWidget->SetResolution(10);
    pWidget->GetPlaneProperty()->SetColor(0.9,0.4,0.4);
    pWidget->GetHandleProperty()->SetColor(0,0.4,0.7);
    pWidget->GetHandleProperty()->SetLineWidth(1.5);
    pWidget->NormalToZAxisOn();
    pWidget->SetRepresentationToSurface();
    pWidget->SetCenter(m_pShift->GetOutput()->GetCenter());
    pWidget->PlaceWidget();
    pWidget->On();

    vtkPlane *pPlane = vtkPlane::New();
    pPlane->SetOrigin(pReader->GetOutput()->GetCenter());
    pPlane->SetNormal(1,0,0);
    pCut = vtkCutter::New();
    pCut->SetCutFunction(pPlane);
    pCut->SetInputConnection(m_pShift->GetOutputPort());
    pCut->Update();

    pCall = vtkWidgetCall::New();
    pCall->pPlane = pPlane;
    pWidget->AddObserver(vtkCommand::EndInteractionEvent,pCall);

    pInt->Initialize();
//    pInt->Start();
    m_Fwidget->SetRenderWindow(pWin);
    m_Fwidget->show();
}

//!------------------------------------------------------------------------
//!
//! \brief CurveReformationWindow::vesselDisplay
//!
void CurveReformationWindow::vesselDisplay(){

    m_Twidget->setStyleSheet("background-color:blue");

}

//!------------------------------------------------------------------------
//!
//! \brief CurveReformationWindow::slicerDisplay
//!
void CurveReformationWindow::slicerDisplay(){
    pRender2 = vtkRenderer::New();
    pWin2 = vtkRenderWindow::New();
    pWin2->AddRenderer(pRender2);

    selectMapper = vtkPolyDataMapper::New();
    selectMapper->SetInputConnection(pCut->GetOutputPort());

    pActor = vtkActor::New();
    pActor->SetMapper(selectMapper);
    pRender2->AddActor(pActor);
    this->m_Swidget->SetRenderWindow(pWin2);
    this->m_Swidget->show();
}

//!------------------------------------------------------------------------
//!
//! \brief CurveReformationWindow::outComingcprDisplay
//!
void CurveReformationWindow::outComingcprDisplay(){
    vtkSmartPointer<vtkSphereSource> sphereSource =
         vtkSmartPointer<vtkSphereSource>::New();
     sphereSource->Update();
     vtkSmartPointer<vtkPolyDataMapper> sphereMapper =
         vtkSmartPointer<vtkPolyDataMapper>::New();
     sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
     vtkSmartPointer<vtkActor> sphereActor =
         vtkSmartPointer<vtkActor>::New();
     sphereActor->SetMapper(sphereMapper);
     // Setup window
     vtkSmartPointer<vtkRenderWindow> renderWindow =
         vtkSmartPointer<vtkRenderWindow>::New();
     // Setup renderer
     vtkSmartPointer<vtkRenderer> renderer =
         vtkSmartPointer<vtkRenderer>::New();
     renderWindow->AddRenderer(renderer);
     renderer->AddActor(sphereActor);
     renderer->ResetCamera();


     boxWidget =vtkBoxWidget::New();
     boxWidget->SetCurrentRenderer(renderer);
     boxWidget->SetPlaceFactor(1.25);
     boxWidget->PlaceWidget();
     callback = vtkMyCallback::New();
     boxWidget->AddObserver(vtkCommand::InteractionEvent,callback);
     boxWidget->On();

     m_Fowidget->setStyleSheet("background-color:blue");

     this->m_Fowidget->SetRenderWindow(renderWindow);
     this->m_Fowidget->show();
}
