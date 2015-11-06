#-------------------------------------------------
#
# Project created by QtCreator 2015-09-07T10:03:34
#
#-------------------------------------------------

QT       += core gui
#CONFIG   += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

unix:QMAKE_CXXFLAGS += -Wno-deprecated

TARGET = igss
TEMPLATE = app

## Define output directories
#DESTDIR = ../bin
#CUDA_OBJECTS_DIR = OBJECTS_DIR/../cuda

# This makes the .cu files appear in your project
#CUDA_SOURCES += \
#    vectorAdd.cu

INCLUDEPATH += SystemDataWare

INCLUDEPATH += GUIs

INCLUDEPATH += GUIs/CurveReformationWindow

INCLUDEPATH += GUIs/GuiComponentLib

INCLUDEPATH += GUIs/GuidewareTrackingWindow

INCLUDEPATH += GUIs/SurgeryPlanWindow

INCLUDEPATH += GUIs/IgssMainWindow

INCLUDEPATH += Dispatchers

INCLUDEPATH += DiskImageReaderFactory

INCLUDEPATH += ImageProcessingMethods

INCLUDEPATH += ImageProcessingMethods/igssGeneralLib

INCLUDEPATH += ImageProcessingMethods/igssMathLib

INCLUDEPATH += ImageProcessingMethods/igssSegmentationLib

RESOURCES = imageresources.qrc

SOURCES +=  main.cpp\
            Dispatchers/SystemDispatcher.cpp \
            SystemDataWare/SystemDataBase.cpp \
            SystemDataWare/IgssImage.cpp \
            ImageProcessingMethods/igssGeneralLib/IgssVtkImageConverter.cpp \
            SystemDataWare/CenterLinePoint.cpp \
            GUIs/IgssMainWindow/IgssMainWindow.cpp \
            SystemDataWare/Patients.cpp \
            SystemDataWare/SystemMetaData.cpp \
            SystemDataWare/Patient.cpp \
            ImageProcessingMethods/igssMathLib/Derivation.cpp \
            ImageProcessingMethods/igssMathLib/Convolution.cpp \
            ImageProcessingMethods/igssSegmentationLib/VesselEnhancementFilter.cpp \
            ImageProcessingMethods/igssSegmentationLib/Options.cpp \
            DiskImageReaderFactory/MRAFileReader.cpp \
            GUIs/IgssMainWindow/PatientsWidget.cpp \
            GUIs/IgssMainWindow/SurgerySystemWidget.cpp \
            GUIs/IgssMainWindow/ReplaysWidget.cpp \
            ImageProcessingMethods/ImageProcessingFactory.cpp \
            ImageProcessingMethods/ErrorMessage.cpp \
            GUIs/IgssMainWindow/AlgorithmTestPlatform.cpp \
            DiskImageReaderFactory/DicomCDRomReader.cpp \
            GUIs/SurgeryPlanWindow/SurgeryPlanWindow.cpp \
            GUIs/GuiComponentLib/CPushButton.cpp \
            GUIs/GuiComponentLib/PlottingBoard.cpp \
            GUIs/GuiComponentLib/ColorPoint.cpp \
            GUIs/GuiComponentLib/HistogramPoint.cpp \
            GUIs/GuiComponentLib/PlotPoint.cpp \
            GUIs/GuiComponentLib/qcustomplot.cpp \
            GUIs/GuiComponentLib/TransferPoint.cpp \
            GUIs/SurgeryPlanWindow/PatientWidgetConfigurationBoard.cpp \
            GUIs/GuiComponentLib/ColorChooseWindow.cpp \
            GUIs/CurveReformationWindow/CurveReformationWindow.cpp \
            GUIs/GuidewareTrackingWindow/GuidewareTrackingWindow.cpp \
            SystemDataWare/CTBidimensionnelFrame.cpp \
            GUIs/IgssMainWindow/PatientInformationWidget.cpp \
            GUIs/IgssMainWindow/PersonnelImageLabel.cpp \
    ImageProcessingMethods/igssGeneralLib/GeneralInformationAnalyser.cpp \
    GUIs/IgssMainWindow/SurgeryLoadingWindow.cpp \
    DiskImageReaderFactory/ImageFileInterface.cpp \
    DiskImageReaderFactory/ImageFileInterface_Dicomdir.cpp \
    DiskImageReaderFactory/ImageFileInterface_RawMhd.cpp \
    ImageProcessingMethods/igssSegmentationLib/kMeansSegmentationAlgorithm.cpp \
    ImageProcessingMethods/igssSegmentationLib/kMeansSegmentationAlgorithm.cpp

HEADERS  += \
            Dispatchers/SystemDispatcher.h \
            SystemDataWare/SystemDataBase.h \
            SystemDataWare/IgssImage.h \
            ImageProcessingMethods/igssGeneralLib/IgssVtkImageConverter.h \
            SystemDataWare/CenterLinePoint.h \
            GUIs/IgssMainWindow/IgssMainWindow.h \
            SystemDataWare/Patients.h \
            SystemDataWare/SystemMetaData.h \
            SystemDataWare/Patient.h \
            ImageProcessingMethods/igssMathLib/Derivation.h \
            ImageProcessingMethods/igssMathLib/Convolution.h \
            ImageProcessingMethods/igssSegmentationLib/VesselEnhancementFilter.h \
            ImageProcessingMethods/igssSegmentationLib/Options.h \
            DiskImageReaderFactory/MRAFileReader.h \
            GUIs/IgssMainWindow/PatientsWidget.h \
            GUIs/IgssMainWindow/SurgerySystemWidget.h \
            GUIs/IgssMainWindow/ReplaysWidget.h \
            ImageProcessingMethods/ImageProcessingFactory.h \
            ImageProcessingMethods/ErrorMessage.h \
            GUIs/IgssMainWindow/AlgorithmTestPlatform.h \
            DiskImageReaderFactory/DicomCDRomReader.h \
            GUIs/SurgeryPlanWindow/SurgeryPlanWindow.h \
            GUIs/GuiComponentLib/CPushButton.h \
            GUIs/GuiComponentLib/PlottingBoard.h \
            GUIs/GuiComponentLib/ColorPoint.h \
            GUIs/GuiComponentLib/HistogramPoint.h \
            GUIs/GuiComponentLib/PlotPoint.h \
            GUIs/GuiComponentLib/qcustomplot.h \
            GUIs/GuiComponentLib/TransferPoint.h \
            GUIs/SurgeryPlanWindow/PatientWidgetConfigurationBoard.h \
            GUIs/GuiComponentLib/ColorChooseWindow.h \
            GUIs/CurveReformationWindow/CurveReformationWindow.h \
            GUIs/GuidewareTrackingWindow/GuidewareTrackingWindow.h \
            GUIs/IgssMainWindow/PatientInformationWidget.h\
            SystemDataWare/CTBidimensionnelFrame.h \
            GUIs/IgssMainWindow/PersonnelImageLabel.h \
    ImageProcessingMethods/igssGeneralLib/GeneralInformationAnalyser.h \
    GUIs/IgssMainWindow/SurgeryLoadingWindow.h \
    DiskImageReaderFactory/ImageFileInterface.h \
    DiskImageReaderFactory/ImageFileInterface_Dicomdir.h \
    DiskImageReaderFactory/ImageFileInterface_RawMhd.h \
    ImageProcessingMethods/igssSegmentationLib/kMeansSegmentationAlgorithm.h \
    ImageProcessingMethods/igssSegmentationLib/kMeansSegmentationAlgorithm.h


win32:INCLUDEPATH += "C:\Program Files\VTK\include\vtk-6.2"
unix:INCLUDEPATH += $$PWD/../../../../../usr/local/include/vtk-6.2
unix:DEPENDPATH += $$PWD/../../../../../usr/local/include/vtk-6.2

unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkalglib-6.2 -lvtkChartsCore-6.2 -lvtkCommonColor-6.2 -lvtkCommonComputationalGeometry-6.2 -lvtkCommonCore-6.2 -lvtkCommonDataModel-6.2 -lvtkCommonExecutionModel-6.2 -lvtkCommonMath-6.2 -lvtkCommonMisc-6.2  -lvtkCommonSystem-6.2  -lvtkCommonTransforms-6.2  -lvtkDICOMParser-6.2  -lvtkDomainsChemistry-6.2  -lvtkexoIIc-6.2  -lvtkexpat-6.2  -lvtkFiltersAMR-6.2  -lvtkFiltersCore-6.2  -lvtkFiltersExtraction-6.2  -lvtkFiltersFlowPaths-6.2  -lvtkFiltersGeneral-6.2  -lvtkFiltersGeneric-6.2  -lvtkFiltersGeometry-6.2  -lvtkFiltersHybrid-6.2  -lvtkFiltersHyperTree-6.2  -lvtkFiltersImaging-6.2  -lvtkFiltersModeling-6.2  -lvtkFiltersParallel-6.2  -lvtkFiltersParallelImaging-6.2  -lvtkFiltersProgrammable-6.2  -lvtkFiltersSelection-6.2  -lvtkFiltersSMP-6.2  -lvtkFiltersSources-6.2  -lvtkFiltersStatistics-6.2  -lvtkFiltersTexture-6.2  -lvtkFiltersVerdict-6.2  -lvtkfreetype-6.2  -lvtkftgl-6.2  -lvtkGeovisCore-6.2  -lvtkgl2ps-6.2  -lvtkGUISupportQt-6.2  -lvtkGUISupportQtOpenGL-6.2  -lvtkGUISupportQtSQL-6.2  -lvtkGUISupportQtWebkit-6.2  -lvtkhdf5-6.2  -lvtkhdf5_hl-6.2  -lvtkImagingColor-6.2  -lvtkImagingCore-6.2  -lvtkImagingFourier-6.2  -lvtkImagingGeneral-6.2  -lvtkImagingHybrid-6.2  -lvtkImagingMath-6.2  -lvtkImagingMorphological-6.2  -lvtkImagingSources-6.2  -lvtkImagingStatistics-6.2  -lvtkImagingStencil-6.2  -lvtkInfovisCore-6.2  -lvtkInfovisLayout-6.2  -lvtkInteractionImage-6.2  -lvtkInteractionStyle-6.2  -lvtkInteractionWidgets-6.2  -lvtkIOAMR-6.2  -lvtkIOCore-6.2  -lvtkIOEnSight-6.2  -lvtkIOExodus-6.2  -lvtkIOExport-6.2  -lvtkIOGeometry-6.2  -lvtkIOImage-6.2 -lvtkIOImport-6.2  -lvtkIOInfovis-6.2  -lvtkIOLegacy-6.2  -lvtkIOLSDyna-6.2  -lvtkIOMINC-6.2  -lvtkIOMovie-6.2  -lvtkIONetCDF-6.2  -lvtkIOParallel-6.2  -lvtkIOParallelXML-6.2  -lvtkIOPLY-6.2  -lvtkIOSQL-6.2  -lvtkIOVideo-6.2  -lvtkIOXML-6.2  -lvtkIOXMLParser-6.2  -lvtkjpeg-6.2  -lvtkjsoncpp-6.2  -lvtklibxml2-6.2  -lvtkmetaio-6.2  -lvtkNetCDF-6.2  -lvtkNetCDF_cxx-6.2  -lvtkoggtheora-6.2  -lvtkParallelCore-6.2  -lvtkpng-6.2  -lvtkproj4-6.2  -lvtkRenderingAnnotation-6.2  -lvtkRenderingContext2D-6.2  -lvtkRenderingContextOpenGL-6.2  -lvtkRenderingCore-6.2  -lvtkRenderingFreeType-6.2  -lvtkRenderingFreeTypeOpenGL-6.2  -lvtkRenderingGL2PS-6.2  -lvtkRenderingImage-6.2  -lvtkRenderingLabel-6.2 -lvtkRenderingLIC-6.2 -lvtkRenderingLOD-6.2 -lvtkRenderingOpenGL-6.2 -lvtkRenderingQt-6.2 -lvtkRenderingVolume-6.2 -lvtkRenderingVolumeOpenGL-6.2 -lvtksqlite-6.2 -lvtksys-6.2 -lvtktiff-6.2 -lvtkverdict-6.2 -lvtkViewsContext2D-6.2 -lvtkViewsCore-6.2 -lvtkViewsInfovis-6.2 -lvtkViewsQt-6.2 -lvtkzlib-6.2

# importer des librairies de vtk...
win32:LIBS += $$quote(C:\Program Files\VTK\lib\QVTKWidgetPlugin.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkalglib-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkChartsCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonColor-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonComputationalGeometry-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonDataModel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonExecutionModel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonMath-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonMisc-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonSystem-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonTransforms-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkDICOMParser-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkDomainsChemistry-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkexoIIc-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkexpat-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersAMR-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersExtraction-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersFlowPaths-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersGeneral-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersGeneric-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersGeometry-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersHybrid-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersHyperTree-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersImaging-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersModeling-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersParallel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersParallelImaging-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersProgrammable-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersSelection-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersSMP-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersSources-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersStatistics-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersTexture-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersVerdict-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkfreetype-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkftgl-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGeovisCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkgl2ps-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGUISupportQt-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGUISupportQtOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGUISupportQtSQL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGUISupportQtWebkit-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkhdf5-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkhdf5_hl-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingColor-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingFourier-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingGeneral-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingHybrid-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingMath-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingMorphological-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingSources-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingStatistics-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingStencil-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInfovisCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInfovisLayout-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInteractionImage-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInteractionStyle-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInteractionWidgets-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOAMR-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOEnSight-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOExodus-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOExport-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOGeometry-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOImage-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOImport-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOInfovis-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOLegacy-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOLSDyna-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOMINC-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOMovie-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIONetCDF-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOParallel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOParallelXML-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOPLY-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOSQL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOVideo-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOXML-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOXMLParser-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkjpeg-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkjsoncpp-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtklibxml2-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkmetaio-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkNetCDF-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkNetCDF_cxx-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkoggtheora-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkParallelCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkpng-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkproj4-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingAnnotation-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingContext2D-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingContextOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingFreeType-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingFreeTypeOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingGL2PS-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingImage-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingLabel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingLIC-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingLOD-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingQt-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingVolume-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingVolumeOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtksqlite-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtksys-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtktiff-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkverdict-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkViewsContext2D-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkViewsCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkViewsInfovis-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkViewsQt-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkzlib-6.2.lib)


#win32:INCLUDEPATH += "C:\Program Files\ITK\include\ITK-4.7"
#unix:INCLUDEPATH += "/usr/local/include/ITK-4.7"
#macx: INCLUDEPATH += $$PWD/../../../../../usr/local/include/ITK-4.7
#macx: DEPENDPATH += $$PWD/../../../../../usr/local/include/ITK-4.7

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../Program Files/ITK/lib/ -lITKBiasCorrection-4.7 -lITKBioCell-4.7 -lITKCommon -lITKDICOMParser-4.7 -litkdouble-conversion-4.7 -lITKEXPAT-4.7 -lITKFEM-4.7 -litkgdcmCommon-4.7 -litkgdcmDICT-4.7 -litkgdcmDSED-4.7 -litkgdcmIOD-4.7 -litkgdcmjpeg8-4.7 -litkgdcmjpeg12-4.7 -litkgdcmjpeg16-4.7 -litkgdcmMSFF-4.7 -lITKgiftiio-4.7 -litkhdf5_cpp-4.7 -litkhdf5-4.7 -lITKIOBioRad-4.7 -lITKIOBMP-4.7 -lITKIOCSV-4.7 -lITKIOGDCM-4.7 -lITKIOGE-4.7 -lITKIOGIPL-4.7 -lITKIOHDF5-4.7 -lITKIOImageBase-4.7 -lITKIOIPL-4.7 -lITKIOJPEG-4.7 -lITKIOLSM-4.7 -lITKIOMesh-4.7 -lITKIOMeta-4.7 -lITKIOMRC-4.7 -lITKIONIFTI-4.7 -lITKIONRRD-4.7 -lITKIOPNG-4.7 -lITKIOSiemens-4.7 -lITKIOSpatialObjects-4.7 -lITKIOStimulate-4.7 -lITKIOTIFF-4.7 -lITKIOTransformBase-4.7 -lITKIOTransformHDF5-4.7 -lITKIOTransformInsightLegacy-4.7 -lITKIOTransformMatlab-4.7 -lITKIOVTK-4.7 -lITKIOXML-4.7 -litkjpeg-4.7 -lITKKLMRegionGrowing-4.7 -lITKLabelMap-4.7 -lITKMesh-4.7 -lITKMetaIO-4.7 -litkNetlibSlatec-4.7 -lITKniftiio-4.7 -lITKNrrdIO-4.7 -litkopenjpeg-4.7 -lITKOptimizers-4.7 -lITKOptimizersv4-4.7 -lITKPath-4.7 -litkpng-4.7 -lITKPolynomials-4.7 -lITKQuadEdgeMesh-4.7 -lITKSpatialObjects-4.7 -lITKStatistics-4.7 -litksys-4.7 -litktiff-4.7 -litkv3p_lsqr-4.7 -litkv3p_netlib-4.7 -litkvcl-4.7 -lITKVideoCore-4.7 -lITKVideoIO-4.7 -litkvnl_algo-4.7 -litkvnl-4.7 -lITKVNLInstantiation-4.7 -lITKVTK-4.7 -lITKWatersheds-4.7 -litkzlib-4.7 -lITKznz-4.7
#unix: LIBS += -L$$PWD/usr/local/lib/ -lITKBiasCorrection-4.7 -lITKBioCell-4.7 -lITKCommon-4.7 -lITKDICOMParser-4.7 -litkdouble-conversion-4.7 -lITKEXPAT-4.7 -lITKFEM-4.7 -litkgdcmCommon-4.7 -litkgdcmDICT-4.7 -litkgdcmDSED-4.7 -litkgdcmIOD-4.7 -litkgdcmjpeg8-4.7 -litkgdcmjpeg12-4.7 -litkgdcmjpeg16-4.7 -litkgdcmMSFF-4.7 -lITKgiftiio-4.7 -litkhdf5_cpp-4.7 -litkhdf5-4.7 -lITKIOBioRad-4.7 -lITKIOBMP-4.7 -lITKIOCSV-4.7 -lITKIOGDCM-4.7 -lITKIOGE-4.7 -lITKIOGIPL-4.7 -lITKIOHDF5-4.7 -lITKIOImageBase-4.7 -lITKIOIPL-4.7 -lITKIOJPEG-4.7 -lITKIOLSM-4.7 -lITKIOMesh-4.7 -lITKIOMeta-4.7 -lITKIOMRC-4.7 -lITKIONIFTI-4.7 -lITKIONRRD-4.7 -lITKIOPNG-4.7 -lITKIOSiemens-4.7 -lITKIOSpatialObjects-4.7 -lITKIOStimulate-4.7 -lITKIOTIFF-4.7 -lITKIOTransformBase-4.7 -lITKIOTransformHDF5-4.7 -lITKIOTransformInsightLegacy-4.7 -lITKIOTransformMatlab-4.7 -lITKIOVTK-4.7 -lITKIOXML-4.7 -litkjpeg-4.7 -lITKKLMRegionGrowing-4.7 -lITKLabelMap-4.7 -lITKMesh-4.7 -lITKMetaIO-4.7 -litkNetlibSlatec-4.7 -lITKniftiio-4.7 -lITKNrrdIO-4.7 -litkopenjpeg-4.7 -lITKOptimizers-4.7 -lITKOptimizersv4-4.7 -lITKPath-4.7 -litkpng-4.7 -lITKPolynomials-4.7 -lITKQuadEdgeMesh-4.7 -lITKSpatialObjects-4.7 -lITKStatistics-4.7 -litksys-4.7 -litktiff-4.7 -litkv3p_lsqr-4.7 -litkv3p_netlib-4.7 -litkvcl-4.7 -lITKVideoCore-4.7 -lITKVideoIO-4.7 -litkvnl_algo-4.7 -litkvnl-4.7 -lITKVNLInstantiation-4.7 -lITKVTK-4.7 -lITKWatersheds-4.7 -litkzlib-4.7 -lITKznz-4.7
#macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lITKBiasCorrection-4.7 -lITKBioCell-4.7 -lITKCommon-4.7 -lITKDICOMParser-4.7 -litkdouble-conversion-4.7 -lITKEXPAT-4.7 -lITKFEM-4.7 -litkgdcmCommon-4.7 -litkgdcmDICT-4.7 -litkgdcmDSED-4.7 -litkgdcmIOD-4.7 -litkgdcmjpeg8-4.7 -litkgdcmjpeg12-4.7 -litkgdcmjpeg16-4.7 -litkgdcmMSFF-4.7 -lITKgiftiio-4.7 -litkhdf5_cpp-4.7 -litkhdf5-4.7 -lITKIOBioRad-4.7 -lITKIOBMP-4.7 -lITKIOCSV-4.7 -lITKIOGDCM-4.7 -lITKIOGE-4.7 -lITKIOGIPL-4.7 -lITKIOHDF5-4.7 -lITKIOImageBase-4.7 -lITKIOIPL-4.7 -lITKIOJPEG-4.7 -lITKIOLSM-4.7 -lITKIOMesh-4.7 -lITKIOMeta-4.7 -lITKIOMRC-4.7 -lITKIONIFTI-4.7 -lITKIONRRD-4.7 -lITKIOPNG-4.7 -lITKIOSiemens-4.7 -lITKIOSpatialObjects-4.7 -lITKIOStimulate-4.7 -lITKIOTIFF-4.7 -lITKIOTransformBase-4.7 -lITKIOTransformHDF5-4.7 -lITKIOTransformInsightLegacy-4.7 -lITKIOTransformMatlab-4.7 -lITKIOVTK-4.7 -lITKIOXML-4.7 -litkjpeg-4.7 -lITKKLMRegionGrowing-4.7 -lITKLabelMap-4.7 -lITKMesh-4.7 -lITKMetaIO-4.7 -litkNetlibSlatec-4.7 -lITKniftiio-4.7 -lITKNrrdIO-4.7 -litkopenjpeg-4.7 -lITKOptimizers-4.7 -lITKOptimizersv4-4.7 -lITKPath-4.7 -litkpng-4.7 -lITKPolynomials-4.7 -lITKQuadEdgeMesh-4.7 -lITKSpatialObjects-4.7 -lITKStatistics-4.7 -litksys-4.7 -litktiff-4.7 -litkv3p_lsqr-4.7 -litkv3p_netlib-4.7 -litkvcl-4.7 -lITKVideoCore-4.7 -lITKVideoIO-4.7 -litkvnl_algo-4.7 -litkvnl-4.7 -lITKVNLInstantiation-4.7 -lITKVTK-4.7 -lITKWatersheds-4.7 -litkzlib-4.7 -lITKznz-4.7

#INCLUDEPATH += $$PWD/../../../../../usr/local/include/ITK-4.7
#DEPENDPATH += $$PWD/../../../../../usr/local/include/ITK-4.7


#-------------------------------------------------

## MSVCRT link option (static or dynamic, it must be the same with your Qt SDK link option)
#MSVCRT_LINK_FLAG_DEBUG   = "/MDd"
#MSVCRT_LINK_FLAG_RELEASE = "/MD"

## CUDA settings
#CUDA_DIR = "D:/CUDA"                # Path to cuda toolkit install
#SYSTEM_NAME = x64                 # Depending on your system either 'Win32', 'x64', or 'Win64'
#SYSTEM_TYPE = 64                    # '32' or '64', depending on your system
#CUDA_ARCH = sm_30                   # Type of CUDA architecture
#NVCC_OPTIONS = --use_fast_math

## include paths
#INCLUDEPATH += $$CUDA_DIR/include \

## library directories
#QMAKE_LIBDIR += $$CUDA_DIR/lib/$$SYSTEM_NAME \

## The following makes sure all path names (which often include spaces) are put between quotation marks
#CUDA_INC = $$join($$CUDA_DIR/include,'" -I"','-I"','"')

## Add the necessary libraries
#CUDA_LIB_NAMES = cudart_static kernel32 user32 gdi32 winspool comdlg32 \
#                 advapi32 shell32 ole32 oleaut32 uuid odbc32 odbccp32 \
#                 #freeglut glew32

#for(lib, CUDA_LIB_NAMES) {
#    CUDA_LIBS += -l$$lib
#}
#LIBS += $$CUDA_LIBS

## Configuration of the Cuda compiler
#CONFIG(debug, debug|release) {
#    # Debug mode
#    cuda_d.input = CUDA_SOURCES
#    cuda_d.output = $$CUDA_OBJECTS_DIR/${QMAKE_FILE_BASE}_cuda.obj
#    cuda_d.commands = $$CUDA_DIR/bin/nvcc.exe -D_DEBUG $$NVCC_OPTIONS $$CUDA_INC $$CUDA_LIBS \
#                      --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH \
#                      --compile -cudart static -g -DWIN32 -D_MBCS \
#                      -Xcompiler "/wd4819,/EHsc,/W3,/nologo,/Od,/Zi,/RTC1" \
#                      -Xcompiler $$MSVCRT_LINK_FLAG_DEBUG \
#                      -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}
#    cuda_d.dependency_type = TYPE_C
#    QMAKE_EXTRA_COMPILERS += cuda_d
#}
#else {
#    # Release mode
#    cuda.input = CUDA_SOURCES
#    cuda.output = $$CUDA_OBJECTS_DIR/${QMAKE_FILE_BASE}_cuda.obj
#    cuda.commands = $$CUDA_DIR/bin/nvcc.exe $$NVCC_OPTIONS $$CUDA_INC $$CUDA_LIBS \
#                    --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH \
#                    --compile -cudart static -DWIN32 -D_MBCS \
#                    -Xcompiler "/wd4819,/EHsc,/W3,/nologo,/O2,/Zi" \
#                    -Xcompiler $$MSVCRT_LINK_FLAG_RELEASE \
#                    -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}
#    cuda.dependency_type = TYPE_C
#    QMAKE_EXTRA_COMPILERS += cuda

#}
