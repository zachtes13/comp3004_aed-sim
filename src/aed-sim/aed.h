#ifndef AED_H
#define AED_H

#include <QString>
#include <QVector>

class AED {
    public:
        AED();
        ~AED();
        bool selfTest();
        void drainBattery();
        void updateDisplay(QString);
        int getBatteryLevel();
        bool isPadsPluggedIn();
        bool isPoweredOn();
        void setBatteryLevel(int);
        void setPadsPluggedIn(bool);
        void togglePower();
        //void setCurrentStage(AEDStage*);

    private:
        int batteryLevel;
        bool padsPluggedIn;
        bool poweredOn;
        QString displayValue;
        //AEDStage currentStage;
        //QVector<AEDStage*> stages;
};

#endif
