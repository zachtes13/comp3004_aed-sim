#ifndef HELPSTAGE_H
#define HELPSTAGE_H

#include "aedStage.h"

/* Class Purpose: The help stage for the AED
*
* Data Members:
* - QTimer* stageTimer: A QTimer that runs for the length of time that the help stage takes place
*
* Class Functions:
* - void start(): The sequential walkthrough of the help stage of the AED.
* - void getHelp(): Simulates the user getting help
*/

class HelpStage : public AEDStage {

    public:
        HelpStage();
        ~HelpStage();
        void start();
        void getHelp();

    private:
        QTimer* stageTimer;
};
#endif
