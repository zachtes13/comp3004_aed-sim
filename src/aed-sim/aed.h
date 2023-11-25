#ifndef AED_H
#define AED_H

#include <QString>
#include <QVector>
#include <QObject>
#include "aedStage.h"

class AED : public QObject {
    Q_OBJECT

    public:
        AED();
        ~AED();
        bool selfTest();
        void drainBattery();
        int getBatteryLevel();
        bool isPadsPluggedIn();
        bool isPoweredOn();
        void setBatteryLevel(int);
        void setPadsPluggedIn(bool);
        void togglePower();
        void setCurrentStage(AEDStage*);
    private:
        int batteryLevel;
        bool padsPluggedIn;
        bool poweredOn;
        QString displayValue;
        AEDStage *currentStage;
        QVector<AEDStage*> stages;

    signals:
        void updateDisplay(QString);
};

#endif
