#include <QThread>
#include "aed.h"
#include "constants.h"
#include "responsivenessStage.h"
#include "helpStage.h"
#include "electrodeStage.h"
#include "analysisStage.h"
#include "shockStage.h"
#include "cprStage.h"

AED::AED() {
    batteryLevel = 100;
    padsPluggedIn = true;
    poweredOn = false;
    displayValue = "";
    currentStage = NULL;
    stages.append(new ResponsivenessStage());
    stages.append(new HelpStage());
    stages.append(new ElectrodeStage());
    stages.append(new AnalysisStage());
    stages.append(new ShockStage());
    stages.append(new CprStage());
}

AED::~AED() {
    for (int i = 0; i < stages.length(); i++) {
        delete stages.at(i);
    }
}

bool AED::selfTest() {
    qDebug("Performing self test...");
    QThread::sleep(1);
    bool isBatteryInsufficient = batteryLevel < MINIMUM_BATTERY_CAPACITY;
    if (isBatteryInsufficient || !padsPluggedIn) {
        if (isBatteryInsufficient) {
            updateDisplay("CHANGE BATTERIES.");
            QThread::sleep(3);
        }
        updateDisplay("UNIT FAILED.");
        QThread::sleep(2);
        return false;
    }
    updateDisplay("UNIT OK.");
    QThread::sleep(2);
    return true;
}

void AED::drainBattery() {
    batteryLevel--;
}

int AED::getBatteryLevel() {
    return batteryLevel;
}

AEDStage* AED::getCurrentStage() {
    return currentStage;
}

QVector<AEDStage*> AED::getStages() {
    return stages;
}

bool AED::isPadsPluggedIn() {
    return padsPluggedIn;
}

bool AED::isPoweredOn() {
    return poweredOn;
}

void AED::setBatteryLevel(int newBatteryLevel) {
    batteryLevel = newBatteryLevel;
}

void AED::setPadsPluggedIn(bool newPadsPluggedIn) {
    padsPluggedIn = newPadsPluggedIn;
}

void AED::togglePower() {
    poweredOn = !poweredOn;
}

void AED::setCurrentStage(AEDStage *newStage) {
    currentStage = newStage;
}
