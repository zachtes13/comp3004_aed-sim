#ifndef AED_H
#define AED_H

#include <QString>
#include <QVector>
#include <QObject>
#include "aedStage.h"
#include "constants.h"
#include "victim.h"

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

};
#endif
