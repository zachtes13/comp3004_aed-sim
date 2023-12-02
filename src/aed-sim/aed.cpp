#include <QThread>
#include <QRandomGenerator>
#include "aed.h"
#include "constants.h"
#include "responsivenessStage.h"
#include "helpStage.h"
#include "electrodeStage.h"
#include "analysisStage.h"
#include "shockStage.h"
#include "cprStage.h"

AED::AED(Victim *_victim) {
    batteryLevel = 100;
    padsPluggedIn = true;
    poweredOn = false;
    displayValue = "";
    currentStage = NULL;
    status = PASS;
    shockCount = 0;
    stages.append(new ResponsivenessStage());
    stages.append(new HelpStage());
    stages.append(new ElectrodeStage());
    stages.append(new AnalysisStage(_victim));
    stages.append(new ShockStage(_victim));
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
    padsPluggedIn = QRandomGenerator::global()->generate() % 2 == 1;
    bool isBatteryInsufficient = batteryLevel < MINIMUM_BATTERY_CAPACITY;
    if (isBatteryInsufficient || !padsPluggedIn) {
        if (isBatteryInsufficient) {
            updateDisplay("CHANGE BATTERIES.");
            QThread::sleep(3);
        }
        setStatus(FAIL);
        return false;
    }
    setStatus(PASS);
    return true;
}

void AED::drainBattery() {
    batteryLevel - 3 < 1 ? batteryLevel = 0 : batteryLevel -= 3;
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

STATUS AED::getStatus() {
    return status;
}

int AED::getShockCount() {
    return shockCount;
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

void AED::setStatus(STATUS newStatus) {
    status = newStatus;
    updateStatusDisplay(newStatus);
}

void AED::incrementShockCount() {
    shockCount++;
}
