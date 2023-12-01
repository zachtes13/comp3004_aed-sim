#ifndef AED_H
#define AED_H

#include <QString>
#include <QVector>
#include <QObject>
#include "aedStage.h"
#include "electrodeStage.h"
#include "constants.h"

class AED : public QObject {
    Q_OBJECT

    public:
        AED();
        ~AED();

        bool selfTest();
        void togglePower();
        void drainBattery();
        bool isPoweredOn();
        bool isPadsPluggedIn();
        int getBatteryLevel();
        STATUS getStatus();
        AEDStage* getCurrentStage();
        QVector<AEDStage*> getStages();

        void connectCable(bool);
        void setBatteryLevel(int);
        void setPadsPluggedIn(bool);
        void setCurrentStage(AEDStage*);
        void setStatus(STATUS);

    private:
        int batteryLevel;
        bool padsPluggedIn;
        bool poweredOn;
        QString displayValue;
        AEDStage *currentStage;
        QVector<AEDStage*> stages;
        STATUS status;

    signals:
        void updateDisplay(QString);
        void updateStatusDisplay(STATUS);
        void updateCable(bool);
};
#endif
