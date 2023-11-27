#include "analysisStage.h"

AnalysisStage::AnalysisStage() {
    displayText = "ANALYZING.";
    orderInSequence = 3;
}

AnalysisStage::~AnalysisStage() { }

void AnalysisStage::start() {
    updateDisplay(displayText);
    QThread::sleep(1);
}
