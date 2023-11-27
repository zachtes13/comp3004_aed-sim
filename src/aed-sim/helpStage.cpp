#include "helpStage.h"

HelpStage::HelpStage() {
    displayText = "CALL FOR HELP.";
    orderInSequence = 1;
}

HelpStage::~HelpStage() { }

void HelpStage::start() {
    qDebug() << "INSIDE HELP STAGE";

    updateDisplay(displayText);
    QThread::sleep(1);
    qDebug() << "User calls or sends for help.";
    QThread::sleep(1);
}
