#include "responsivenessStage.h"

ResponsivenessStage::ResponsivenessStage() {
    displayText = "CHECK RESPONSIVENESS.";
    orderInSequence = 0;
}

ResponsivenessStage::~ResponsivenessStage() { }

void ResponsivenessStage::start() {
    qDebug() << "INSIDE RESPONSIVENESS STAGE";

    updateDisplay(displayText);
    QThread::sleep(1);
}

