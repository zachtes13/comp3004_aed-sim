#include <QRandomGenerator>
#include "shockStage.h"

ShockStage::ShockStage(Victim *_victim) {
    orderInSequence = StageOrderInSequence::SHOCK_STAGE;
    victim = _victim;
    displayText = victim->isShockable() ? "SHOCK WILL BE DELIVERED IN THREE." : "NO SHOCK ADVISED.";
}

ShockStage::~ShockStage() { }

void ShockStage::start() {
    if (victim->isShockable()) {
        bool isShockDelivered = false;
        bool isShockInterrupt = QRandomGenerator::global()->generate() % 100 < 30;
        while (!isShockDelivered && isShockInterrupt) {
            countdown();
            while (isShockInterrupt) {
                updateDisplay("NO SHOCK DELIVERED.");
                isShockInterrupt = QRandomGenerator::global()->generate() % 100 < 30;
                QThread::sleep(1);
            }
            isShockDelivered = true;
        }
        countdown();
        updateDisplay("SHOCK DELIVERED.");
        incrementShockCount();
        drainBattery();
    }
    else {
        updateDisplay("NO SHOCK DELIVERED.");
    }
    nextStage();
}

void ShockStage::countdown() {
    updateDisplay("SHOCK WILL BE DELIVERED IN THREE.");
    QThread::sleep(1);
    updateDisplay("SHOCK WILL BE DELIVERED IN TWO.");
    QThread::sleep(1);
    updateDisplay("SHOCK WILL BE DELIVERED IN ONE.");
    QThread::sleep(1);
}

