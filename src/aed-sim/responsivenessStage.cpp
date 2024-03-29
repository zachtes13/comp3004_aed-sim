#include "responsivenessStage.h"

ResponsivenessStage::ResponsivenessStage() {
    displayText = "CHECK RESPONSIVENESS.";
    orderInSequence = StageOrderInSequence::RESPONSIVENESS_STAGE;

    stageTimer = new QTimer(this);
    connect(stageTimer, &QTimer::timeout, this, &ResponsivenessStage::checkResponsiveness);
}

ResponsivenessStage::~ResponsivenessStage() { }

void ResponsivenessStage::start() {
    updateDisplay(displayText);
    stageTimer->start(2000);
}

void ResponsivenessStage::checkResponsiveness() {
    stageTimer->stop();
    qDebug() << "User checks victim's responsiveness.";
    qDebug() << "User determines victim is unresponsive.";
    QThread::sleep(1);
    nextStage();
}
