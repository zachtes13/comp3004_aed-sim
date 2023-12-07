#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QRadioButton>
#include <QString>
#include "aed.h"
#include "victim.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/* Class Purpose: The main window of the application, acts as the controller
*
* Data Members:
* - Ui::MainWindow *ui: a pointer to the UI
* - AED *aed: holds a pointer to the aed which our UI will need to communicate with
* - Victim *victim: holds a pointer to the victim which our UI will need to communicate with
* - QList<QRadioButton*> indicators: a list of radio button indicators, one radio button for each stages
* - int currentStageIndex: holds the value of the current stage we are in the AED
* - QElapsedTimer *elapsedTimer: holds the elapsed timer of power on runtime
*
* Class Function:
* - void incrementStageSequence(): increments the stage sequence, simulates us going to the next stage in the AED
* - void updateIndicators(int): update the radio button indicator to represent the current stage we are on
* - void triggerAedFailure(): trigger a failure of the AED
* - void clearIndicators(): remove all radio buttons to simulate we are not in any AED state
* - void updateCurrentStageIndex(StageOrderInSequence): update the current state index in the AED
* - void initialize(): initialize the UI with providing pictures for the stages, as well as providing "blank" pictures that will be changed when power is turned on
* - void togglePower(): disappears certain elements of the ui to simulate it being turned off
* - void blinkIndicators(): blinks the stage indicators
* - void connectPads(): simulates the user connecting the pads to the victim
* - void updateButtonStatus(BUTTON): enables and disables certain buttons
* - void updateCable(bool): simulates plugging in the cable of the AED
* - void updateTextDisplay(QString): updates the display with the QString that is passed in
* - void updateBatteryDisplay(): updates the battery display in the UI
* - void drainBattery(): drains the battery and updates the battery of the UI
* - void replaceBattery(): simulates battery replacement, sets battery level to 100
* - void victimAwakensOrHelpArrived(): simulates the victim awakening or help being arrived, this is the program terminator.
* - void updateStatusDisplay(STATUS): show a green light on success and a red light on failure
* - void updateECGDisplay(HEART_RATE): set the appropriate ECG picture based on the diagnosis of the victim
* - void updateCPRDisplay(CompressionStatus): updates the CPR display based on the current compression status
* - void updateShockCount(): updates the shock count to be displayed on the UI
* - void startCPR(): simulates cpr starting
* - void stopCPR(): simluates cpr stopping
* - void updateElapsedTime(): update the UI elapsed time display
*/

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
        QTimer *timer;
        QElapsedTimer *elapsedTimer;
        void incrementStageSequence();
        void updateIndicators(int);
        void triggerAedFailure();
        void clearIndicators();
        void updateCurrentStageIndex(StageOrderInSequence);

    private slots:
        void initialize();
        void togglePower();
        void blinkIndicators();
        void connectPads();
        void updateButtonStatus(BUTTON);
        void updateCable(bool);
        void updateTextDisplay(QString);
        void updateBatteryDisplay();
        void drainBattery();
        void replaceBattery();
        void victimAwakensOrHelpArrived();
        void updateStatusDisplay(STATUS);
        void updateECGDisplay(HEART_RATE);
        void updateCPRDisplay(CompressionStatus);
        void updateShockCount();
        void startCPR();
        void stopCPR();
        void updateElapsedTime();
};
#endif
