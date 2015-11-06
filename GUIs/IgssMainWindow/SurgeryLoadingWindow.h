#ifndef SURGERYLOADINGWINDOW_H
#define SURGERYLOADINGWINDOW_H
#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QSlider>

class SurgeryLoadingWindow:public QWidget
{
    Q_OBJECT
public:
    SurgeryLoadingWindow();
    void constructIHM();
    void displaySurgeryLoadingWindow();

    QVBoxLayout* surgeryLoadingWidgetLayout;

    QWidget* surgeryLoadingWidget;

    QSlider* surgeryLoadingSliderBar;

    QSpacerItem* surgeryLoadingItem;
};

#endif // SURGERYLOADINGWINDOW_H
