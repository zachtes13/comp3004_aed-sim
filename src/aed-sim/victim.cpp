#include "victim.h"

Victim::Victim() {
    heartRate = 0; //figure out what to put here.
    isUnconcious = true;
    isChild = false; //user will set this.
    padsOn = false;
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
