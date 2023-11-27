#include "shockStage.h"

ShockStage::ShockStage() {
    displayText = "ANALYZING.";
    orderInSequence = 4;
}

ShockStage::~ShockStage() { }

void ShockStage::start() {
    updateDisplay(displayText);
    QThread::sleep(1);
}

