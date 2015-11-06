#include "kMeansSegmentationAlgorithm.h"

kMeansSegmentationAlgorithm::kMeansSegmentationAlgorithm(int dimNum, int clusterNum)
{

}

//!--------------------------------------------------------------------------------------------
//!
//! \brief kMeansSegmentationAlgorithm::setMean
//! \param i
//! \param u
//!
void kMeansSegmentationAlgorithm::setMean(int i, const double *u){
    memcpy(m_means[i], u, sizeof(double) *m_dimNum);
}

//!--------------------------------------------------------------------------------------------
//!
//! \brief kMeansSegmentationAlgorithm::setInitMode
//! \param j
//!
void kMeansSegmentationAlgorithm::setInitMode(int j){
    this->m_initMode = j;
}

//!--------------------------------------------------------------------------------------------
//!
//! \brief kMeansSegmentationAlgorithm::setMaxIterNum
//! \param k
//!
void kMeansSegmentationAlgorithm::setMaxIterNum(int k){
    this->m_maxIterNum = k;
}

//!--------------------------------------------------------------------------------------------
//!
//! \brief kMeansSegmentationAlgorithm::setEndError
//! \param f
//!
void kMeansSegmentationAlgorithm::setEndError(double f){
    this->m_endError = f;
}

//!--------------------------------------------------------------------------------------------
//!
//! \brief kMeansSegmentationAlgorithm::getMean
//! \param i
//! \return
//!
double* kMeansSegmentationAlgorithm::getMean(int i){
    return this->m_means[i];
}

//!--------------------------------------------------------------------------------------------
//!
//! \brief kMeansSegmentationAlgorithm::getInitMode
//! \return
//!
int kMeansSegmentationAlgorithm::getInitMode(){
    return this->m_initMode;
}

//!--------------------------------------------------------------------------------------------
//!
//! \brief kMeansSegmentationAlgorithm::getMaxIterNum
//! \return
//!
int kMeansSegmentationAlgorithm::getMaxIterNum(){
    return this->m_maxIterNum;
}

//!--------------------------------------------------------------------------------------------
//!
//! \brief kMeansSegmentationAlgorithm::getEndError
//! \return
//!
double kMeansSegmentationAlgorithm::getEndError(){
    return this->m_endError;
}

kMeansSegmentationAlgorithm::~kMeansSegmentationAlgorithm()
{

}

