#include "helpStage.h"

HelpStage::HelpStage() {
    displayText = "CALL FOR HELP.";
    orderInSequence = 1;
}

HelpStage::~HelpStage() { }

void HelpStage::start() {
    qDebug() << "INSIDE HELP STAGE";

    updateDisplay("TESTING UPDATE DISPLAY FROM HELP STAGE START()");
}
