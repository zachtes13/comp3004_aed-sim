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
        void togglePower();
        void drainBattery();

        bool isPoweredOn();
        bool isPadsPluggedIn();
        int getBatteryLevel();
        AEDStage* getCurrentStage();
        QVector<AEDStage*> getStages();

        void setBatteryLevel(int);
        void setPadsPluggedIn(bool);
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
