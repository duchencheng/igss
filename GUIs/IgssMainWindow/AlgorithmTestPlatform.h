#ifndef ALGORITHMTESTPLATFORM_H
#define ALGORITHMTESTPLATFORM_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QSlider>
#include <QFont>
#include <SystemDispatcher.h>


class AlgorithmTestPlatform : public QWidget
{
    Q_OBJECT
public:
    explicit AlgorithmTestPlatform(SystemDispatcher* dispatcher, QFont *caracterStyle, int appWidth, int appHeight);

    void setSystemStatus(QString status);
    void getPatientsStatus();

private:
    void initVariable();
    void constructIHM();
    void setConnections();

private:
    QHBoxLayout* platformLayout;
    QVBoxLayout* terminalWindowLayout;
    QGridLayout* systemUsageStatusLayout;

    QTextEdit* systemStatus;
    QLineEdit* systemCommand;
    SystemDispatcher* dispatcher;

    QFont* caracterStyle;

    QLabel* systemUsageStatusWidget;
    QWidget* terminalWindow;

    QLabel* cpuLabel;
    QLabel* ramLabel;
    QLabel* diskLable;
    QLabel* netLable;

    QSlider* cpuSlider;
    QSlider* ramSlider;
    QSlider* diskSlider;
    QSlider* netSlider;

    QLabel* cpuRateLabel;
    QLabel* ramRateLabel;
    QLabel* diskRateLable;
    QLabel* netRateLable;

    QString labelStyleSheet;
    QString sliderStyleSheet;

    int appWidth;
    int appHeight;

signals:

public slots:
    void doParseCommand();
};

#endif // ALGORITHMTESTPLATFORM_H
