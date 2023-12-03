#include <QRandomGenerator>
#include <QGraphicsPixmapItem>
#include "analysisStage.h"
#include "constants.h"

AnalysisStage::AnalysisStage(Victim *_victim) {
    displayText = "DON'T TOUCH PATIENT, ANALYZING.";
    orderInSequence = StageOrderInSequence::ANALYSIS_STAGE;
    victim = _victim;
}

AnalysisStage::~AnalysisStage() { }

void AnalysisStage::start() {
    updateDisplay(displayText);
    qDebug() << "AED performs analysis.";
    QThread::sleep(2);
    bool isAnalysisInterrupt = QRandomGenerator::global()->generate() % 2 == 1;
    while (isAnalysisInterrupt) {
        updateDisplay("ANALYSIS HALTED. KEEP PATIENT STILL.");
        isAnalysisInterrupt = QRandomGenerator::global()->generate() % 2 == 1;
        QThread::sleep(2);
    }
    updateDisplay(displayText);
    QThread::sleep(2);
    int victimHeartRate = victim->getHeartRate();
    HEART_RATE victimDiagnosis = diagnoseHeartRate(victimHeartRate);
    if (victimDiagnosis == VTACH || victimDiagnosis == VFIB) {
        victim->setShockable(true);
        updateDisplay("SHOCK ADVISED.");
    }
    else {
        victim->setShockable(false);
        updateDisplay("NO SHOCK ADVISED.");
    }
    updateECGDisplay(victimDiagnosis);
    QThread::sleep(2);
    nextStage();
}

HEART_RATE AnalysisStage::diagnoseHeartRate(int heartRate) {
    if (heartRate <= 10) {
        return ASYSTOLE;
    }
    else if (heartRate >= 150) {
        return VTACH;
    }
    else if (heartRate > 100 && heartRate < 150) {
        return VFIB;
    }
    else {
        return NORMAL;
    }
}
