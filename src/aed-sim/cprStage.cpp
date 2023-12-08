#include <QRandomGenerator>
#include "cprStage.h"
#include "constants.h"

CprStage::CprStage() {
    displayText = "START CPR.";
    orderInSequence = StageOrderInSequence::CPR_STAGE;

    startTimer = new QTimer(this);
    connect(startTimer, &QTimer::timeout, this, &CprStage::startCompression);

    stopTimer = new QTimer(this);
    connect(stopTimer, &QTimer::timeout, this, &CprStage::stopCompression);
}

CprStage::~CprStage() { }

void CprStage::start() {
    updateDisplay(displayText);
    QThread::sleep(1);
}

QTimer* CprStage::getStartTimer() {
    return startTimer;
}

QTimer* CprStage::getStopTimer() {
    return stopTimer;
}

void CprStage::startCompression() {
    bool goodOrBadCompressions = QRandomGenerator::global()->generate() % 2 == 0;  //take a random number and modulus two it, basically 50/50 chance for a good or bad compression
    bool isConnectionLost = QRandomGenerator::global()->generate() % 100 < 3;
    if (isConnectionLost) {
        updateDisplay("CHECK ELECTRODE PADS.");
        updateCompressionPicture(CompressionStatus::NO_COMPRESSIONS);
        QThread::sleep(2);
        connectionFailed(FAIL);
        updateCable(false);
        displayText = "START CPR.";
        return;
    }
    if (goodOrBadCompressions) {
        displayText = "GOOD COMPRESSIONS.";
        qDebug() << "User is performing chest compressions at least 2 inches deep on victim.";
        updateDisplay(displayText);
        updateCompressionPicture(CompressionStatus::GOOD_COMPRESSIONS);
    }
    else {
        bool continueCompressions = QRandomGenerator::global()->generate() % 2 == 0;
        if (continueCompressions) {
                displayText = "CONTINUE CPR.";
                updateDisplay(displayText);
                QThread::sleep(1);
        }
        else {
            displayText = "PUSH HARDER.";
            qDebug() << "User is performing chest compressions below 2 inches deep on victim.";
            updateDisplay(displayText);
            updateCompressionPicture(CompressionStatus::BAD_COMPRESSIONS);
        }
    }
    if (!stopTimer->isActive()) {
        stopTimer->start(30000);
    }
}

void CprStage::stopCompression() {
    startTimer->stop();
    stopTimer->stop();
    displayText = "STOP CPR.";
    updateDisplay(displayText);
    qDebug() << "User stops doing chest compressions on victim.";
    updateCompressionPicture(CompressionStatus::NO_COMPRESSIONS);
    displayText = "START CPR.";
    QThread::sleep(2);
    nextStage();
}
