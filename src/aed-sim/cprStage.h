#ifndef CPRSTAGE_H
#define CPRSTAGE_H

#include "aedStage.h"

/* Class Purpose: The CPR stage for the AED
*
* Data Members:
* - QTimer* startTimer: a timer which initates start compression on timeout
* - QTimer* stopTimer: a timer which initates stop compression on timeout
*
* Class Functions:
* - void start(): The sequential walkthrough of the CPR stage of the AED.
* - void startCompression(): simulates starting compressions
* - void stopCompression(): simulates stopping compressions
* - QTimer* startTimer(): the function which starts the cpr timer
* - QTimer* stopTimer(): the function which stops the cpr timer
*/

class CprStage : public AEDStage {
    Q_OBJECT

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

    signals:
        void connectionFailed(STATUS);
        void updateElectrodes(bool);
};
#endif
