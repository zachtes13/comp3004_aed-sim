#ifndef RESPONSIVENESSSTAGE_H
#define RESPONSIVENESSSTAGE_H

#include "aedStage.h"

/* Class Purpose: The responsiveness stage for the AED
*
* Data Members:
* - QTimer* stageTimer: A QTimer that runs for the length of time that the responsiveness stage takes place
*
*
* Class Functions:
* - void start(): The sequential walkthrough of the responsiveness stage of the AED
* - void checkResponsiveness(): A function that checks the victims responsiveness
*/

class ResponsivenessStage : public AEDStage {
    public:
        ResponsivenessStage();
        ~ResponsivenessStage();
        void start();
        void checkResponsiveness();

    private:
        QTimer* stageTimer;
};
#endif
