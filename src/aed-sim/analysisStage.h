#ifndef ANALYSISSTAGE_H
#define ANALYSISSTAGE_H

#include "aedStage.h"
#include "victim.h"

/* Class Purpose: The analysis stage for the AED
*
* Data Members:
* - Victim *victim: a pointer to our victim
*
* Class Functions:
* - void start(): The sequential walkthrough of the analysis stage of the AED.
* - HEART_RATE diagnoseHeartRate(int): a function that returns what type of diagnosis we have based on a given heart rate
* - void updateECGDisplay(HEART_RATE): a signal which updates the ECG display in the UI
*/

class AnalysisStage : public AEDStage {
    Q_OBJECT

    public:
        AnalysisStage(Victim*);
        ~AnalysisStage();
        void start();

    private:
        Victim *victim;
        HEART_RATE diagnoseHeartRate(int);

    signals:
        void updateECGDisplay(HEART_RATE);
};
#endif
