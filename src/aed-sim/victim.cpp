#include <QRandomGenerator>
#include "victim.h"
#include "constants.h"

Victim::Victim() {
    getHeartRate();
    isChild = false;
    shockable = false;
    isUpperPadOn = false;
    isLowerPadOn = false;
    hasPacemaker = QRandomGenerator::global()->bounded(1, 101) < 15;  // There is a 15% chance the victim will have a pacemaker
    isLarge = QRandomGenerator::global()->bounded(1, 101) < 35;       // There is a 35% chance the victim will be large
}

void Victim::setIsChild() {
    isChild = true;
}

void Victim::applyUpperPad() {
    isUpperPadOn = true;
}

void Victim::applyLowerPad() {
    isLowerPadOn = true;
}

int Victim::getHeartRate() {
    heartRate = QRandomGenerator::global()->bounded(MAXIMUM_HEART_RATE);
    return heartRate;
}

bool Victim::getIsChild() {
    return isChild;
}

bool Victim::isShockable() {
    return shockable;
}

void Victim::setShockable(bool shockableState) {
    shockable = shockableState;
}

bool Victim::getIsLarge(){
    return isLarge;
}

bool Victim::getHasPacemaker(){
    return hasPacemaker;
}

bool Victim::getIsUpperPadOn() {
    return isUpperPadOn;
}

bool Victim::getIsLowerPadOn() {
    return isLowerPadOn;
}
