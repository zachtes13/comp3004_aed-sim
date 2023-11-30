#include "analysisStage.h"

AnalysisStage::AnalysisStage() {
    displayText = "DON'T TOUCH PATIENT, ANALYZING.";
    orderInSequence = StageOrderInSequence::ANALYSIS_STAGE;
}

AnalysisStage::~AnalysisStage() { }

void AnalysisStage::start() {
    updateDisplay(displayText);
    QThread::sleep(2);
    qDebug() << "AED performs analysis.";
    QThread::sleep(2);
}
