#ifndef AED_H
#define AED_H

#include <QString>
#include <QVector>
#include <QObject>
#include "aedStage.h"
#include "electrodeStage.h"
#include "constants.h"
#include "victim.h"

/* Class Purpose: The actual AED in the program
*
* Data Members:
* - int batteryLevel: stores the battery level of the AED
* - bool padsPluggedIn: holds whether the AED's pads are plugged in or not
* - bool poweredOn: holds whether the AED is powered on or not
* - QString displayValue: holds the text of what is to be displayed on the AED UI
* - AEDStage *currentStage: holds the current stage we are on the AED
* - QVector<AEDStage*> stages: a vector that holds the 5 AED stages
* - STATUS status: holds where the AED is in a PASS or FAIL status
* - int shockCount: stores the number of shocks that have happened
*
* Class Functions:
* - bool selfTest(): performs the self test of the AED
* - void togglePower(): turns on or off the AED based on whether it is turned on or off
* - void drainBattery(): drain the battery of the AED
* - bool isPoweredOn(): gets whether the AED is turned on
* - bool isPadsPluggedIn(): gets whether the AED's pads are plugged in
* - int getBatteryLevel(): gets the battery level of the AED
* - AEDStage* getCurrentStage(): gets the current stage of the AED
* - QVector<AEDStage*> getStages(): gets all stages of the AED
* - STATUS getStatus(): gets the current status of the AED
* - int getShockCount(): gets the number of shocks the AED did
* - void setBatteryLevel(int): sets the battery level of the AED, usually called when you change the batteries
* - void setPadsPluggedIn(bool): sets whether the pads are plugged in or not
* - void setCurrentStage(AEDStage*): sets the currentStage of the AED based on the stage passed in
* - void setStatus(STATUS): sets the status of the AED
* - void incrementShockCount(): increments the number of shocks the AED did
* - void connectCable(): simulates the user connecting the cable in the AED
* - void updateDisplay(QString): a signal to the mainwindow to update the display message text
* - void updateStatusDisplay(STATUS): a signal to the mainwindow to update the status display
* - void updateCompressionPicture(CompressionStatus): a signal to the mainwindow to update the compression picture
* - void updateCable(bool): a signal to the mainwindow to update the cable
* - void updateStageOrder(StageOrderInSequence): a signal to the mainwindow to update the AED stage
*/

class AED : public QObject {
    Q_OBJECT

    public:
        AED(Victim*);
        ~AED();
        bool selfTest();
        void togglePower();
        void drainBattery();
        bool isPoweredOn();
        bool isPadsPluggedIn();
        int getBatteryLevel();
        AEDStage* getCurrentStage();
        QVector<AEDStage*> getStages();
        STATUS getStatus();
        int getShockCount();
        void setBatteryLevel(int);
        void setPadsPluggedIn(bool);
        void setCurrentStage(AEDStage*);
        void setStatus(STATUS);
        void incrementShockCount();
        void connectCable();

    private:
        int batteryLevel;
        bool padsPluggedIn;
        bool poweredOn;
        QString displayValue;
        AEDStage *currentStage;
        QVector<AEDStage*> stages;
        STATUS status;
        int shockCount;

    signals:
        void updateDisplay(QString);
        void updateStatusDisplay(STATUS);
        void updateCompressionPicture(CompressionStatus);
        void updateCable(bool);
        void updateStageOrder(StageOrderInSequence);
};
#endif
