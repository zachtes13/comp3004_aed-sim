#include "helpStage.h"

HelpStage::HelpStage() {
    displayText = "CALL FOR HELP.";
    orderInSequence = StageOrderInSequence::HELP_STAGE;
}

HelpStage::~HelpStage() { }

void HelpStage::start() {
    updateDisplay(displayText);
    QThread::sleep(2);
    qDebug() << "User calls or sends for help.";
    QThread::sleep(2);
}
