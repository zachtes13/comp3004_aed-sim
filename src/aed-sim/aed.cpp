#include "aed.h"

AED::AED() {
    batteryLevel = 100;
    padsPluggedIn = true;
    poweredOn = false;
    displayValue = "";
}

AED::~AED() {

}

bool AED::selfTest() {

}

void AED::drainBattery() {
    batteryLevel--;
}

void AED::updateDisplay(QString newDisplayValue) {
    displayValue = newDisplayValue;
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
