#ifndef KMEANSSEGMENTATIONALGORITHM_H
#define KMEANSSEGMENTATIONALGORITHM_H

#include <QString>
#include <QFile>

class kMeansSegmentationAlgorithm
{
public:
    enum initMode{
        initRandom,
        initManual,
        initUniform,
    };

    kMeansSegmentationAlgorithm(int dimNum, int clusterNum);
    ~kMeansSegmentationAlgorithm();

    void setMean(int i, const double *u);
    void setInitMode(int j);
    void setMaxIterNum(int k);
    void setEndError(double f);

    double* getMean(int i);
    int getInitMode();
    int getMaxIterNum();
    double getEndError();

    void cluster(const char* sampleFileName, const char* labelFileName);
    void init(QFile &sampleFile);
private:
    int m_dimNum;
    int m_clusterNum;
    double** m_means;

    int m_initMode;
    int m_maxIterNum;
    int m_endError;
};

#endif // KMEANSSEGMENTATIONALGORITHM_H
