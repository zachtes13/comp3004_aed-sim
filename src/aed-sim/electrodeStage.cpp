#include "electrodeStage.h"

ElectrodeStage::ElectrodeStage() {
    displayText = "ATTACH DEFIB PADS TO PATIENT'S BARE CHEST.";
    orderInSequence = StageOrderInSequence::ELECTRODE_STAGE;
}

ElectrodeStage::~ElectrodeStage() { }

void ElectrodeStage::start() {
    updateDisplay(displayText);
    QThread::sleep(2);
    qDebug() << "User applies electrodes.";
    QThread::sleep(2);
}
