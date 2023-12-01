#include "cprStage.h"

CprStage::CprStage() {
    displayText = "START CPR.";
    orderInSequence = StageOrderInSequence::CPR_STAGE;
}

CprStage::~CprStage() { }

void CprStage::start() {
    updateDisplay(displayText);
    QThread::sleep(1);

    qDebug() << "User begins chest compressions on victim.";
    QThread::sleep(1);

    displayText = "CONTINUE CPR.";
    updateDisplay(displayText);


    //This is supposed to go for 2 minutes but i've set it to 25 seconds so that you don't have to wait for 2 minutes (and ui updates every 2 seconds).
    for (int i = 0; i < 25; i += 2) {

        int goodOrBadCompressions = rand() % 2; //take a random number and modulus two it, basically 50/50 chance for a good or bad compression

        if (goodOrBadCompressions == 0) {
            displayText = "GOOD COMPRESSIONS.";
            qDebug() << "User is performing chest compressions at least 2 inches deep on victim.";
            updateDisplay(displayText);
            //also update ui chest compressions stuff.
            updateCompressionPicture(CompressionStatus::GOOD_COMPRESSIONS);
        } else {
            displayText = "PUSH HARDER.";
            qDebug() << "User is performing chest compressions below 2 inches deep on victim.";
            updateDisplay(displayText);
            updateCompressionPicture(CompressionStatus::BAD_COMPRESSIONS);
        }

        QThread::sleep(2);
    }

    displayText = "STOP CPR.";
    updateDisplay(displayText);
    qDebug() << "User stops doing chest compressions on victim.";
    updateCompressionPicture(CompressionStatus::NO_COMPRESSIONS);

    displayText = "START CPR."; //reset the displayText to the original for when cprStage is called again.

}
