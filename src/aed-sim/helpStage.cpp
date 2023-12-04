#include "helpStage.h"

HelpStage::HelpStage() {
    displayText = "CALL FOR HELP.";
    orderInSequence = StageOrderInSequence::HELP_STAGE;

    stageTimer = new QTimer(this);
    connect(stageTimer, &QTimer::timeout, this, &HelpStage::getHelp);
}

HelpStage::~HelpStage() { }

void HelpStage::start() {
    updateDisplay(displayText);
    stageTimer->start(3000);
}

void HelpStage::getHelp() {
    stageTimer->stop();
    qDebug() << "User calls or sends for help.";
    QThread::sleep(1);
    nextStage();
}
