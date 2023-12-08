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
    padsPluggedIn = QRandomGenerator::global()->bounded(1, 101) < 50;    // There is a 50% the pads will be disconnected
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
    bool isBatteryInsufficient = batteryLevel < MINIMUM_BATTERY_CAPACITY;
    if (isBatteryInsufficient || !padsPluggedIn) {
        if (isBatteryInsufficient) {
            updateDisplay("CHANGE BATTERIES.");
            QThread::sleep(1);
        }
        else {
            updateDisplay("PLUG IN CABLE");
            QThread::sleep(1);
            updateCable(false);
        }
        updateStatusDisplay(FAIL);
        QThread::sleep(1);
        return false;
    }
    QThread::sleep(1);
    updateStatusDisplay(PASS);
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
    currentStage = stages.at((int)StageOrderInSequence::RESPONSIVENESS_STAGE);
    shockCount = 0;
}

void AED::setCurrentStage(AEDStage *newStage) {
    currentStage = newStage;
}

void AED::setStatus(STATUS newStatus) {
    status = newStatus;
}

void AED::incrementShockCount() {
    shockCount++;
}

void AED::connectCable() {
    qDebug() << "User reconnects the cable to the AED device.";
    padsPluggedIn = true;
    updateCable(true);
    QThread::sleep(1);
}
