#ifndef SYSTEMDISPATCHER_H
#define SYSTEMDISPATCHER_H

#include <SystemDataBase.h>
#include <QProcess>
#include <QString>
#include <QDir>
#include <QFile>
#include <QTextEdit>
#include "ImageProcessingFactory.h"
#include "ErrorMessage.h"

class SystemDispatcher
{
public:
    SystemDispatcher();
    QString get_username();
    void setMessageDisplayWindow(QTextEdit *msgDisplay);
    void initializeSystemPaths();
    int findPatientExisted();
    void setSystemDataBase(SystemDataBase* database);
    void setImageProcessingFactory(ImageProcessingFactory *imageProcessingFactory);
    QString getImageCenterPath();

    Patient* getPatientById(int id);

    QStringList getPatientsStatus();
    QString doImageProcessingByMethodType(int id, int dim, QString method);

private:
    SystemDataBase* database;
    ImageProcessingFactory *imageProcessingFactory;

    //! -------------create a workspace folder with the default path----------------------------------------
    QString workspace_path;
    QString patients_path;
    QString metadata_path;
    QString image_center_path;

    IgssImage *output;

};

#endif // SYSTEMDISPATCHER_H
