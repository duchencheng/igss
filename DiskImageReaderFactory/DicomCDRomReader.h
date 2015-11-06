#ifndef DICOMCDROMREADER_H
#define DICOMCDROMREADER_H

#include <QString>

class DicomCDRomReader
{
public:
    DicomCDRomReader();

    void doParseCDRom(QString dicomDirPath);
};

#endif // DICOMCDROMREADER_H
