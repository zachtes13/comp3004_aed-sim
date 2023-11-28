#include "shockStage.h"

ShockStage::ShockStage() {
    displayText = "SHOCK ADVISED.";
    orderInSequence = StageOrderInSequence::SHOCK_STAGE;
}

ShockStage::~ShockStage() { }

void ShockStage::start() {
    updateDisplay(displayText);
    QThread::sleep(2);
    QThread::sleep(2);
    qDebug() << "AED performs shock.";
    QThread::sleep(2);
}

