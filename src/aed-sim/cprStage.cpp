#include "cprStage.h"

CprStage::CprStage() {
    displayText = "PERFORM CPR.";
    orderInSequence = 5;
}

CprStage::~CprStage() { }

void CprStage::start() {
    qDebug() << "INSIDE CPR STAGE";
}
