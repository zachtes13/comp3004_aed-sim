#include "electrodeStage.h"

ElectrodeStage::ElectrodeStage() {
    displayText = "PLACE ELECTRODES.";
    orderInSequence = 2;
}

ElectrodeStage::~ElectrodeStage() { }

void ElectrodeStage::start() {
    updateDisplay(displayText);
    QThread::sleep(1);
}
