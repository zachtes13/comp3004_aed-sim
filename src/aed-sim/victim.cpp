#include "victim.h"
#include <QRandomGenerator>

Victim::Victim() {
    heartRate = 0; //figure out what to put here.
    isUnconcious = true;
    isChild = false; //user will set this.
    isUpperPadOn = false;
    isLowerPadOn = false;

    // There is a 15% chance the victim will have a pacemake
    if(QRandomGenerator::global()->bounded(1, 101) < 15){
        hasPacemaker = true;
    }
    // There is a 35% chance the victim will be large
    if(QRandomGenerator::global()->bounded(1, 101) < 35){
        isLarge = true;
    }
}

void Victim::setIsChild() {
    isChild = true;
}

void Victim::receiveShock() {
    //need to figure out function implementation for this.
}

//void Victim::applyPads() {
//    padsOn = true;
//}

//void Victim::removePads() {
//    padsOn = false;
//}

void Victim::applyUpperPad() {
    isUpperPadOn = true;
}
void Victim::applyLowerPad() {
    isLowerPadOn = true;
}
void Victim::removeUpperPad() {
    isUpperPadOn = false;
}
void Victim::removeLowerPad() {
    isLowerPadOn = false;
}

bool Victim::isFlatlined() {
       if (heartRate == 0) {
              return true;
       } else {
              return false;
       }
}

int Victim::getHeartRate() {
    return heartRate;
}

bool Victim::getUnconcious() {
    return isUnconcious;
}

bool Victim::getIsChild() {
    return isChild;
}

//bool Victim::getPadsOn() {
//    return padsOn;
//}

bool Victim::getIsUpperPadOn() {
    return isUpperPadOn;
}

bool Victim::getIsLowerPadOn() {
    return isLowerPadOn;
}
