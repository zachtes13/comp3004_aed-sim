#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QRadioButton>
#include <QString>
#include "aed.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        AED *aed;
        Victim *victim;
        QList<QRadioButton*> indicators;
        int currentStageIndex;
        void incrementStageSequence();
        void updateIndicators(int);
        void triggerAedFailure();
        void clearIndicators();

    private slots:
        void initialize();
        void togglePower();
        void blinkIndicators();
        void updateTextDisplay(QString);
        void updateBatteryDisplay();
        void drainBattery();
        void replaceBattery();
        void victimAwakensOrHelpArrived();
        void updateStatusDisplay(STATUS);
        void updateECGDisplay(HEART_RATE);
        void updateCPRDisplay(CompressionStatus);
        void updateShockCount();
};
#endif
