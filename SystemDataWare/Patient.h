#ifndef PATIENT_H
#define PATIENT_H
#include <QList>
#include <IgssImage.h>
#include <QFileInfo>
#include <QDir>
#include <QThread>
#include <QString>
#include <QStringList>
#include "MRAFileReader.h"
#include "vtkImageData.h"
#include <vtkSmartPointer.h>
#include "IgssVtkImageConverter.h"
#include "ImageProcessingFactory.h"
#include "ImageFileInterface.h"
#include <HistogramPoint.h>
#include <ColorPoint.h>
#include <TransferPoint.h>


class Patient
{
private:
    class ThreadImageProcessing : public QThread{
        public:
            void run();
            Patient *patient;
    };

public:
    Patient(QString myPath, int id);
    int getIdNumber();
    bool readFinished();
    QString getBirthdayOfPatient();
    void doImageProcessing();
    QString getMRAPath();
    QString getName();

    QString getFirstName();
    QString getLastName();

    QString getSex();
    QString getPhotoPath();
    IgssImage *getOriginImage();
    vtkImageData *getMraImageToBeDisplayed();
    void setImageProcessingFactory(ImageProcessingFactory* imageProcessingFactory);
    bool loadMRAImageFile(const QString &fileName);
    void setMRAImage(vtkImageData *personnelMRAImage);

    QStringList getMriStatisticsList();
    QVector<HistogramPoint*> getMriHistogramfrequencies();

    QVector<HistogramPoint*> getGrayScaleValuefrequencies();
    QVector<TransferPoint*> getOpacityTransferPoints();
    QVector<ColorPoint*> getColorTransferPoints();
    QVector<TransferPoint*> getGradientTransferPoints();

    int getColorTransferPointsNumber();

    int findPointInTolerentArea(double abscissa, double ordinate, QString transformationFormat);

    void setGrayScaleValueFrequencies(QVector<HistogramPoint*> frequencies);
    void setOpacityTransferPoint(TransferPoint* opacityPoint);
    void setColorTransferPoint(ColorPoint* redPoint);
    void setGradientTransferPoint(TransferPoint* gradientPoint);

    int getMaximumGrayscaleValue();
    int getMinimumGrayscaleValue();

    int getGrayScaleValueByIndex(int index, QString option);
    double getOpacityValueByIndex(int index);
    double getGradientValueByIndex(int index);
    double getRedValueByIndex(int index);
    double getGreenValueByIndex(int index);
    double getBlueValueByIndex(int index);

    void updateOpacityPoint(int index, int abscissa, double ordinate);
    void updateGradientPoint(int index, int abscissa, double ordinate);
    void updateColorPoint(int index, int abscissa);



private:
    QVector<HistogramPoint*> frequencies;

    QVector<TransferPoint*> opacityTransferPoints;
    QVector<ColorPoint*> colorTransferPoints;
    QVector<TransferPoint*> gradientTransferPoints;

    QStringList statisticsList;

    int maximumGrayScaleValue;
    int minimumGrayScaleValue;

    bool MraImageReadComplete;

    QString myPath;
    QString myPhotoPath;

    //! personnel informations
    QString name;
    QString birthday;
    QString firstName;
    QString lastName;
    QString sex;
    QString IdentityNumber;
    int imageExtents[6];

    int age;
    int id;

    ImageProcessingFactory* imageProcessingFactory;

    //! tridimensionnel Image (MRA)
    IgssImage *originImage;
    vtkImageData* MriImageForDisplay;

    //! bidimensionnel Image (CT) captured while operation
    QList<IgssImage *> cImageSequence;

    //! parameter of image......

    //! Handle du thread
    ThreadImageProcessing imageProcessingThread;
    MRAFileReader *mhdFileReader;

};

#endif // PATIENT_H
