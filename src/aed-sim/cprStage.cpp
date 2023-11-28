#include "cprStage.h"

CprStage::CprStage() {
    displayText = "START CPR.";
    orderInSequence = StageOrderInSequence::CPR_STAGE;
}

CprStage::~CprStage() { }

void CprStage::start() {
    updateDisplay(displayText);
    QThread::sleep(2);
    qDebug() << "User performs CPR.";
    QThread::sleep(2);
}
