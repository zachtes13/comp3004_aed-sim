#include "cprStage.h"

CprStage::CprStage() {
    displayText = "START CPR.";
    orderInSequence = StageOrderInSequence::CPR_STAGE;
}

CprStage::~CprStage() { }

void CprStage::start() {
    updateDisplay(displayText);

    QThread::sleep(1);

    qDebug() << "User begins chest compressions on victim.";
    QThread::sleep(5);

    displayText = "CONTINUE CPR.";
    updateDisplay(displayText);

    QThread::sleep(115); //User completes 2 minutes CPR.

    //ASK: do we want to check for good compressions or not? (2 inches deep) - would involve displaying GOOD COMPRESSIONS or BAD COMPRESSIONS

    displayText = "STOP CPR.";
    updateDisplay(displayText);
    qDebug() << "User stops doing chest compressions on victim.";
}
