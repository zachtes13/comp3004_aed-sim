#include <QThread>
#include "aed.h"
#include "constants.h"
#include "responsivenessstage.h"

AED::AED() {
    batteryLevel = 100;
    padsPluggedIn = true;
    poweredOn = false;
    displayValue = "";
    currentStage = NULL;
    stages.append(new ResponsivenessStage());
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
