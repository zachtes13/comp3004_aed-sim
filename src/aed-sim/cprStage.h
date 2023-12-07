#ifndef CPRSTAGE_H
#define CPRSTAGE_H

#include "aedStage.h"

/* Class Purpose: The CPR stage for the AED
*
* Data Members:
* - QTimer* startTimer:
* - QTimer* stopTimer:
*
* Class Functions:
* - void start(): The sequential walkthrough of the CPR stage of the AED.
* - void startCompression():
* - void stopCompression():
* - QTimer* startTimer():
* - QTimer* stopTimer():
*/

class CprStage : public AEDStage {
    public:
        CprStage();
        ~CprStage();
        void start();

        void startCompression();
        void stopCompression();

        QTimer* getStartTimer();
        QTimer* getStopTimer();

    private:
        QTimer* startTimer;
        QTimer* stopTimer;
};
#endif
