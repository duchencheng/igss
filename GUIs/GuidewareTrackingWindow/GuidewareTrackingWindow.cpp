#include "GuidewareTrackingWindow.h"

GuidewareTrackingWindow::GuidewareTrackingWindow(QRect rect,
                                                 SystemDispatcher* systemDispatcher) : QWidget(){
    this->x = rect.x();
    this->y = rect.y();
    this->width = rect.width();
    this->height = rect.height();
    this->systemDispatcher = systemDispatcher;
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);// | Qt::WindowStaysOnTopHint);
    this->setWindowOpacity(1);
    this->setMouseTracking(true);
    this->setAutoFillBackground(true);
    this->initVariable();
    this->constructionIHM();
    this->setConnections();
    this->drawBackground();
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief GuidewareTrackingWindow::~GuidewareTrackingWindow
//!
GuidewareTrackingWindow::~GuidewareTrackingWindow(){

}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief GuidewareTrackingWindow::displayWindow
//!
void GuidewareTrackingWindow::displayWindow(){
    this->resize(this->width, this->height);
    this->move(this->x, this->y);
    this->show();
}

//!
//! \brief GuidewareTrackingWindow::initVariable
//!
void GuidewareTrackingWindow::initVariable(){
    this->caracterStyle = new QFont("Times",12,QFont::AnyStyle, false);
    this->windowStyleSheet = "border: 1px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue";
}

//!
//! \brief GuidewareTrackingWindow::constructionIHM
//!
void GuidewareTrackingWindow::constructionIHM(){
    //!----------------------------------------------------------------------------------------------------
    //! name bar:display name of this window
    //!----------------------------------------------------------------------------------------------------
    this->nameBar = new QWidget();
    this->nameBar->setFixedSize(width*0.20,height*0.04);
    this->nameBar->setStyleSheet(this->windowStyleSheet);

    //!----------------------------------------------------------------------------------------------------
    //! vtk display bar:display name of VTKImage
    //!----------------------------------------------------------------------------------------------------
    this->vtkDisplayBar = new QWidget();
    this->vtkDisplayBar->setStyleSheet(this->windowStyleSheet);

    //!----------------------------------------------------------------------------------------------------
    //! surgery information:including surgerID,patientName,surgeryDate
    //!----------------------------------------------------------------------------------------------------
    this->surgeryID = new QLabel();
    this->surgeryID = new QLabel("surgeryID:");
    this->surgeryID->setFont(*this->caracterStyle);
    this->surgeryID->setStyleSheet("border: 0px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue");

    this->patientName = new QLabel();
    this->patientName = new QLabel("patientName:");
    this->patientName->setFont(*this->caracterStyle);
    this->patientName->setStyleSheet("border: 0px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue");
    this->surgeryDate = new QLabel();
    this->surgeryDate = new QLabel("surgeryDate:");
    this->surgeryDate->setFont(*this->caracterStyle);
    this->surgeryDate->setStyleSheet("border: 0px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue");

    this->surgeryInformation = new QWidget();
    this->surgeryInformation->setFixedHeight(height*0.16);
    this->surgeryInformation->setStyleSheet(this->windowStyleSheet);
    this->surgeryInformationLayout = new QVBoxLayout(this->surgeryInformation);
    this->surgeryInformationLayout->addWidget(surgeryID);
    this->surgeryInformationLayout->addWidget(patientName);
    this->surgeryInformationLayout->addWidget(surgeryDate);
    this->surgeryInformationLayout->setMargin(0);
    this->surgeryInformationLayout->setSpacing(0);

    //!----------------------------------------------------------------------------------------------------
    //! control button area
    //!----------------------------------------------------------------------------------------------------
    this->untitledButton1 = new QPushButton("X");
    this->untitledButton1->setFixedSize(width*0.2*0.2, width*0.2*0.2);
    this->untitledButton2 = new QPushButton("-");
    this->untitledButton2->setFixedSize(width*0.2*0.2, width*0.2*0.2);
    this->untitledButton3 = new QPushButton("-");
    this->untitledButton3->setFixedSize(width*0.2*0.2, width*0.2*0.2);
    this->untitledButton4 = new QPushButton("^");
    this->untitledButton4->setFixedSize(width*0.2*0.2, width*0.2*0.2);
    this->controlButtonArea = new QWidget();
    this->controlButtonArea->setFixedHeight(height*0.4);
    this->controlButtonAreaLayout = new QGridLayout(this->controlButtonArea);
    this->controlButtonAreaLayout->addWidget(this->untitledButton1, 0, 0);
    this->controlButtonAreaLayout->addWidget(this->untitledButton2, 0, 1);
    this->controlButtonAreaLayout->addWidget(this->untitledButton3, 0, 3);
    this->controlButtonAreaLayout->addWidget(this->untitledButton4, 0, 4);
    this->controlButtonAreaLayout->setMargin(0);
    this->controlButtonAreaLayout->setSpacing(0);




    //!----------------------------------------------------------------------------------------------------
    //! unknown area
    //!----------------------------------------------------------------------------------------------------
    this->unknownArea = new QWidget();


    //!----------------------------------------------------------------------------------------------------
    //!guideControlBoard:including guideControlBoard,controlButtonArea,unknownArea
    //!----------------------------------------------------------------------------------------------------
    this->guideControlBoard = new QWidget();
    this->guideControlBoard->setStyleSheet(this->windowStyleSheet);
    this->guideControlBoardLayout = new QVBoxLayout(this->guideControlBoard);
    this->guideControlBoardLayout->addWidget(this->surgeryInformation);
    this->guideControlBoardLayout->addWidget(this->controlButtonArea);
    this->guideControlBoardLayout->addWidget(this->unknownArea);
    this->guideControlBoardLayout->setMargin(0);
    this->guideControlBoardLayout->setSpacing(0);


    //!----------------------------------------------------------------------------------------------------
    //!primary display
    //!----------------------------------------------------------------------------------------------------
    this->primaryDisplay = new QWidget();
    primaryDisplay->setFixedSize(width*0.40,height*0.80);
    l_layout = new QHBoxLayout(primaryDisplay);
    f_vtkwidget = new QVTKWidget();
    f_vtkwidget->setStyleSheet("background-color:red");
    f_vtkwidget->setFixedSize(width*0.35,height*0.75);
    l_layout->addWidget(f_vtkwidget);


    //!----------------------------------------------------------------------------------------------------
    //!guideware tracking display
    //!----------------------------------------------------------------------------------------------------
    this->guidewareTrackingDisplay = new QWidget();

    //!----------------------------------------------------------------------------------------------------
    //!vtkDisplayBoard:including primaryDisplay,guidewareTrackingDisplay
    //!----------------------------------------------------------------------------------------------------
    this->vtkDisplayBoard = new QWidget();
    this->vtkDisplayBoard->setStyleSheet(this->windowStyleSheet);
    this->vtkDisplayBoardLayout = new QHBoxLayout(this->vtkDisplayBoard);
    this->vtkDisplayBoardLayout->addWidget(primaryDisplay);
    this->vtkDisplayBoardLayout->addWidget(guidewareTrackingDisplay);
    this->vtkDisplayBoardLayout->setMargin(0);
    this->vtkDisplayBoardLayout->setSpacing(0);

    //!----------------------------------------------------------------------------------------------------
    //!main window
    //!----------------------------------------------------------------------------------------------------
    this->guidewareTrackingLayout = new QGridLayout(this);
    this->guidewareTrackingLayout->addWidget(this->nameBar, 0, 0);
    this->guidewareTrackingLayout->addWidget(this->vtkDisplayBar, 0, 1);
    this->guidewareTrackingLayout->addWidget(this->guideControlBoard, 1, 0);
    this->guidewareTrackingLayout->addWidget(this->vtkDisplayBoard, 1, 1);

}

//!
//! \brief GuidewareTrackingWindow::setConnections
//!
void GuidewareTrackingWindow::setConnections(){
    this->connect(untitledButton1, SIGNAL(clicked()), this, SLOT(closeSystem()));
    this->connect(untitledButton4, SIGNAL(clicked()), this, SLOT(VTKDisplay()));
}

//!
//! \brief GuidewareTrackingWindow::closeSystem
//!
void GuidewareTrackingWindow::closeSystem(){
    this->close();
}

void GuidewareTrackingWindow::VTKDisplay(){

//    pixmap = new QPixmap(":/images/background.png");
//    QPalette p =  this->palette();

//    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(this->width, this->height), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));

//    this->primaryDisplay->setPalette(p);
//    this->primaryDisplay->setMask(pixmap->mask());
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

     f_vtkwidget->setStyleSheet("background-color:blue");

     this->f_vtkwidget->SetRenderWindow(renderWindow);
     this->f_vtkwidget->show();

}

//!--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief GuidewareTrackingWindow::drawBackground
//!
void GuidewareTrackingWindow::drawBackground(){
    pixmap = new QPixmap(":/images/background_darkBlue.png");
    QPalette p =  this->palette();

    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(this->width, this->height), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));

    this->setPalette(p);
    this->setMask(pixmap->mask());
}

void GuidewareTrackingWindow::testVtkwidget(){

}
