#include "responsivenessStage.h"

ResponsivenessStage::ResponsivenessStage() {
    displayText = "CHECK RESPONSIVENESS.";
    orderInSequence = StageOrderInSequence::RESPONSIVENESS_STAGE;
}

ResponsivenessStage::~ResponsivenessStage() { }

void ResponsivenessStage::start() {
//    updateDisplay(displayText);
    QThread::sleep(2);
    qDebug() << "User checks victim's responsiveness.";
    QThread::sleep(2);
    qDebug() << "VICTIM IS UNRESPONSIVE.";
    nextStage();
}

