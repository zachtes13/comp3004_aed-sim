#include <QRandomGenerator>
#include "victim.h"
#include "constants.h"

Victim::Victim() {
    getHeartRate();
    isUnconcious = true;
    isChild = false; //user will set this.
    padsOn = false;
    shockable = false;
}

void Victim::receiveShock() {
    //need to figure out function implementation for this.
}

void Victim::applyPads() {
    padsOn = true;
}

void Victim::removePads() {
    padsOn = false;
}

bool Victim::isFlatlined() {
       if (heartRate == 0) {
              return true;
       } else {
              return false;
       }
}

int Victim::getHeartRate() {
    heartRate = QRandomGenerator::global()->bounded(MAXIMUM_HEART_RATE);
    return heartRate;
}

bool Victim::getUnconcious() {
    return isUnconcious;
}

bool Victim::getIsChild() {
    return isChild;
}

bool Victim::getPadsOn() {
    return padsOn;
}

bool Victim::isShockable() {
    return shockable;
}

void Victim::setShockable(bool shockableState) {
    shockable = shockableState;
}
